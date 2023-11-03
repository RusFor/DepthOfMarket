#include "Tester.h"
#include "Generator.h"

#include <iostream>

using namespace std::literals;

bool Tester::TestAddingOrders(unsigned int amount) {
	std::cerr << "TestAddingBids started with amount "sv << amount;
	auto bids = generator_.GenerateAmountOfOrders(amount);
	for (auto& bid : bids) {
		dom_.AddOrder(static_cast<Order::Type>(generator_.GenerateUInt() >> 1), bid);
	}
	std::cerr << " OK!\n";
	return true;
}

bool Tester::TestChangeOrders(unsigned int amount) {
	std::cerr << "TestChangeBid started with amount "sv << amount ;

	std::cerr << " OK!\n";
	return true;
}

