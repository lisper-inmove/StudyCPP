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
	 * 尾返回类型（Trailing return type），是 C++11 引入的语法。如果 返回值 依赖于模板参数，普通 写法会比较困难，
	 * 需要使用尾返回类型
	 * template <class F, class... Args>: 可变参数模板，接收一个函数(F)和多个参数(Args...)
	 * -> 尾返回类型语法，std::future<std::invoke_result_t<F, Args...>> 是实际返回类型
	 * std::invoke_result_t<F, Args...> 表示 函数f调用后的返回类型
	 *
	 * class... Args 是 C++11 引入的一个语法，称为 可变参数模板（Variadic Templates）。
	 * template <class... Args>
        void printTypes() {
        std::cout << "Number of types: " << sizeof...(Args) << std::endl;
       }
	   printTypes<int, double, std::string>();
	 */
	template <class F, class... Args>
	auto enqueue(F&& f, Args&&... args) -> std::future<std::invoke_result_t<F, Args...>> {
		// 推导 用Args... 调用函数F，返回的类型是ReturnType
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