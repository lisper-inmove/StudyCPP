#pragma once

#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <atomic>

class ThreadPool {
public:
	explicit ThreadPool(size_t threadCount = std::thread::hardware_concurrency()): stop(false) {
		for (size_t i = 0; i < threadCount; i++) {
			workers.emplace_back([this]() {
				while (true) {
					Task task;
					{
						std::unique_lock<std::mutex> lock(this->queueMutex);
						condition.wait(lock, [this]() {return stop || !tasks.empty(); });
						if (stop && tasks.empty()) return;
						task = std::move(tasks.front());
						tasks.pop();
					}
					task();
				}
			});
		}
	}
	~ThreadPool() {
		{
			std::lock_guard<std::mutex> lock(queueMutex);
			stop = true;
		}
		condition.notify_all();
		for (auto& worker : workers) {
			worker.join();
		}
	}

	/**
	 * β�������ͣ�Trailing return type������ C++11 ������﷨����� ����ֵ ������ģ���������ͨ д����Ƚ����ѣ�
	 * ��Ҫʹ��β��������
	 * template <class F, class... Args>: �ɱ����ģ�壬����һ������(F)�Ͷ������(Args...)
	 * -> β���������﷨��std::future<std::invoke_result_t<F, Args...>> ��ʵ�ʷ�������
	 * std::invoke_result_t<F, Args...> ��ʾ ����f���ú�ķ�������
	 *
	 * class... Args �� C++11 �����һ���﷨����Ϊ �ɱ����ģ�壨Variadic Templates����
	 * template <class... Args>
        void printTypes() {
        std::cout << "Number of types: " << sizeof...(Args) << std::endl;
       }
	   printTypes<int, double, std::string>();
	 */
	template <class F, class... Args>
	auto enqueue(F&& f, Args&&... args) -> std::future<std::invoke_result_t<F, Args...>> {
		// �Ƶ� ��Args... ���ú���F�����ص�������ReturnType
		using ReturnType = std::invoke_result_t<F, Args...>;
		auto taskPtr = std::make_shared<std::packaged_task<ReturnType()>>(
			std::bind(std::forward<F>(f), std::forward<Args>(args)...)
		);
		std::future<ReturnType> res = taskPtr->get_future();
		{
			std::lock_guard<std::mutex> lock(queueMutex);
			if (stop) throw std::runtime_error("Enqueue on stopped ThreadPool");
			tasks.emplace([taskPtr]() {(*taskPtr)(); });
		}
		condition.notify_all();
		return res;
	}
private:
	using Task = std::function<void()>;
	std::vector<std::thread> workers;
	std::queue<Task> tasks;
	std::mutex queueMutex;
	std::condition_variable condition;
	std::atomic<bool> stop;
};

//ThreadPool pool(4);
//auto future1 = pool.enqueue([] {
//	std::cout << "Hello from thread!" << std::endl;
//	return 42;
//	});
//auto future2 = pool.enqueue([](int x) {
//	return x * x;
//	}, 8);
//std::cout << "future1: " << future1.get() << std::endl;
//std::cout << "future2: " << future2.get() << std::endl;