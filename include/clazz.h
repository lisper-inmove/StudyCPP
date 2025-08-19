#pragma once
#include <string>
#include <iostream>

using namespace std;

class MyClazz {
private:
	string name_;
public:
	MyClazz(const string &name);
	MyClazz(const MyClazz& other);
	MyClazz(MyClazz&& other) noexcept;
	MyClazz& operator=(const MyClazz& other);
	MyClazz& operator=(MyClazz&& other) noexcept;
	~MyClazz();
	void printName() const
	{
		cout << "Name: " << name_ << " Address: " << &name_ << endl;
	}
	void setName(const string& name);
};