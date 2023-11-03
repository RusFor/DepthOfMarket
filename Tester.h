#pragma once

#include "OrderBook.h"
#include "Generator.h"

class OrderBookTester {
public:
	void TestAddOrder();
	void TestChangeAmountOfOrder();
	void TestDeleteOrder();
	void TestGetTopOrders();
private:
	Generator generator_;
};

