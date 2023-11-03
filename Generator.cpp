#include "Generator.h"

#include <time.h>
#include <stdlib.h>
#include <vector>

Order Generator::GenerateOrder() {
	return { GenerateUInt(), GenerateUInt() };
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
	std::srand(time(nullptr));
	return rand();
}
