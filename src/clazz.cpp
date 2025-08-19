#include <string>
#include <iostream>
#include "clazz.h"

using namespace std;

MyClazz::MyClazz(const string &name) : name_(name) {
	// ��ͨ���캯��
	cout << "Constructor called" << endl;
}
MyClazz::MyClazz(const MyClazz& other) :name_(other.name_) {
	// �������캯��
	cout << "Copy Constructor called" << endl;
}
MyClazz::MyClazz(MyClazz&& other) noexcept : name_(std::move(other.name_)) {
	// �ƶ����캯��
	cout << "Move Constructor called" << endl;
}
MyClazz& MyClazz::operator=(const MyClazz& other) {
	// ������ֵ�����
	cout << "Copy Assignment Operator called" << endl;
	if (this != &other) {
		name_ = other.name_;
	}
	return *this;
}
MyClazz& MyClazz::operator=(MyClazz&& other) noexcept {
	// �ƶ���ֵ�����
	cout << "Move Assignment Operator called" << endl;
	if (this != &other) {
		name_ = std::move(other.name_);
	}
	return *this;
}
MyClazz::~MyClazz() {
	// ��������
	cout << "Destructor called" << endl;
}

void MyClazz::setName(const string& name) {
	name_ = name;
}