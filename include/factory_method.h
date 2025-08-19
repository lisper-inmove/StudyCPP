#pragma once

#include <iostream>
#include <memory>

class Transport {
public:
	virtual void deliver() = 0;
};

class Truck : public Transport {
public:
	void deliver() override {
		std::cout << "Truck transport\n";
	}
};

class Ship : public Transport {
public:
	void deliver() override {
		std::cout << "Ship transport\n";
	}
};

class Logistics {
public:
	void planDelivery() {
		auto t = createTransport();
		t->deliver();
	}
	virtual std::unique_ptr<Transport> createTransport() = 0;
};

class RoadLogistics : public Logistics {
public:
	std::unique_ptr<Transport> createTransport() override {
		return std::make_unique<Truck>();
	}
};

class SeaLogistics : public Logistics {
public:
	std::unique_ptr<Transport> createTransport() override {
		return std::make_unique<Ship>();
	}
};

/**
 *
 *#include <vector>
#include <iostream>
#include "factory_method.h"

using namespace std;

int main()
{
	Logistics *l1 = new RoadLogistics();
	l1->planDelivery();

	Logistics* l2 = new SeaLogistics();
	l2->planDelivery();
	return 0;
}
 *
 * 
 */