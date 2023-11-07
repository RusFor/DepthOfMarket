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
	void CompareTwoOrders(const Order& order1, const Order& order2) const;
};

std::ostream& operator<<(std::ostream& out, const Order& order);
