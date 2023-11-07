#include "Generator.h"

#include <random>
#include <stdlib.h>
#include <vector>

Order Generator::GenerateOrder() {
	return { GenerateUInt(), GenerateUInt() };
}

Order::Type Generator::GenerateOrderType() {
	return static_cast<Order::Type>(GenerateUInt() & 1);
}

std::vector<Order> Generator::GenerateAmountOfOrders(unsigned int amount) {
	std::vector<Order> orders;
	orders.reserve(amount);
	while (amount > 0) {
		orders.push_back(GenerateOrder());
		--amount;
	}
	return orders;
}

unsigned int Generator::GenerateUInt() {
	std::random_device rd; 
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0u, 10000u);
	return distrib(gen);
}
