#pragma once

#include "OrderBook.h"
#include "Generator.h"

class Tester{
public:
	Tester(OrderBook& dom) 
	: dom_(dom){}

	Tester() = delete;
	Tester(const Tester&) = delete;
	Tester(Tester&&) = delete;
	Tester operator=(const Tester&) = delete;
	Tester operator=(Tester&&) = delete;

	bool TestAddingOrders(unsigned int amount);
	bool TestChangeOrders(unsigned int amount);
	bool TestDeleteOrders(unsigned int amount);
	bool TestShowBestOrders(unsigned int amount);
private:
	OrderBook& dom_;
	Generator generator_;

};

