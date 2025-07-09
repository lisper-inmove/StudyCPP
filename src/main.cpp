#include <iostream>
#include "my_smart_ptr.h"

int main() {
    shared_ptr<int> ptr1(new int(10));
    shared_ptr<int> ptr2 = ptr1;
    std::cout << "ptr1: " << *ptr1 << "," << *ptr2 << std::endl;
    ptr1.reset();
    // Error
    // std::cout << "ptr1: " << *ptr1 << std::endl;
    std::cout << "ptr: " << *ptr2 << std::endl;

    shared_ptr<int> ptr3 = std::move(ptr2);
    std::cout << "ptr: " << *ptr3 << std::endl;
    // Error
    // std::cout << "ptr: " << *ptr2 << std::endl;

    return 0;
}
