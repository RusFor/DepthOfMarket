#pragma once

#include <vector>


#include "Order.h"

class Generator {
public:
	unsigned int GenerateUInt();
	Order GenerateOrder();
	Order::Type GenerateOrderType();
	std::vector<Order> GenerateAmountOfOrders(unsigned int amount);
private:

};

