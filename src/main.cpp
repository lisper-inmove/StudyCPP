#include <iostream>
#include <memory>
#include <ostream>
#include <utility>

void smart_pointer() {
    // 1. 一个对象只能被一个unique_ptr管理，不能复制，只能移动
    std::unique_ptr<int> p1 = std::make_unique<int>(10);
    // std::unique_ptr<int> p2 = p1;
    std::unique_ptr<int> p2 = std::move(p1);
    std::cout << p1 << std::endl;

    // 2. 多个 shared_ptr 可以共同管理同一个对象，内部维护引用计数。
    std::shared_ptr<int> p3 = std::make_shared<int>(11);
    std::shared_ptr<int> p4 = p3;  // 引用计数+1
    std::cout << *p3 << "," << *p4 << std::endl;
    *p3 = 13;
    std::cout << *p3 << "," << *p4 << std::endl;

    // 3. 不拥有资源，仅做观察者，不影响引用计数；避免循环引用。
    std::shared_ptr<int> p5 = std::make_shared<int>(12);
    std::weak_ptr<int> p6   = p5;  // 没有引用计数
    if (auto tmp = p6.lock()) {
        *tmp = 13;
        std::cout << ">>" << *tmp << ">>" << std::endl;
    } else {
        std::cout << "Expired" << std::endl;
    }
    std::cout << ">>" << *p5 << ">>" << std::endl;
}

int main() {
    smart_pointer();
    return 0;
}
