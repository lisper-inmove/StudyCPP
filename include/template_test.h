#pragma once

#include <iostream>

void template_test();

template <typename T>
T myMax(T const a, T const b) {
	return a > b ? a : b;
}

class Device {
public:
	virtual void output() = 0;
	virtual ~Device() = default;
};

template <void (*action)()>
class SmartDevice: public Device
{
public:
	void output() override
	{
		(*action)();
	}
};