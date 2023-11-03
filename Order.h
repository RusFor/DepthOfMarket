#pragma once
#include <limits>



struct Order {
	enum class Type {
		Ask,
		Bid
	};
	Order(unsigned int new_price, unsigned int new_amount)
		: price(new_price)
		, amount(new_amount) {}
	unsigned int price;
	unsigned int amount;

	bool operator <(Order& other);
	bool operator >(Order& other);
};

