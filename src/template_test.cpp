#include <iostream>
#include <memory>
#include <template_test.h>

using namespace std;

void say_hello_in_english()
{
	std::cout << "Hello!" << std::endl;
}

void say_hello_in_spanish()
{
	std::cout << "Hola mundo!\n";
}

void template_test() {
	int c = myMax<int>(1, 2);
	int d = myMax(3, 4);
	int e = myMax<>(7.1, 9.2);
	cout << "Max of 1 and 2 is: " << c << endl;

	auto w1 = std::make_unique<SmartDevice<&say_hello_in_english>>();
	auto w2 = std::make_unique<SmartDevice<&say_hello_in_spanish>>();
	w1->output();
	w2->output();
}

