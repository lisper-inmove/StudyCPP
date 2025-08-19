#include <string>
#include <iostream>
#include "clazz.h"

using namespace std;

MyClazz::MyClazz(const string &name) : name_(name) {
	// 普通构造函数
	cout << "Constructor called" << endl;
}
MyClazz::MyClazz(const MyClazz& other) :name_(other.name_) {
	// 拷贝构造函数
	cout << "Copy Constructor called" << endl;
}
MyClazz::MyClazz(MyClazz&& other) noexcept : name_(std::move(other.name_)) {
	// 移动构造函数
	cout << "Move Constructor called" << endl;
}
MyClazz& MyClazz::operator=(const MyClazz& other) {
	// 拷贝赋值运算符
	cout << "Copy Assignment Operator called" << endl;
	if (this != &other) {
		name_ = other.name_;
	}
	return *this;
}
MyClazz& MyClazz::operator=(MyClazz&& other) noexcept {
	// 移动赋值运算符
	cout << "Move Assignment Operator called" << endl;
	if (this != &other) {
		name_ = std::move(other.name_);
	}
	return *this;
}
MyClazz::~MyClazz() {
	// 析构函数
	cout << "Destructor called" << endl;
}

void MyClazz::setName(const string& name) {
	name_ = name;
}