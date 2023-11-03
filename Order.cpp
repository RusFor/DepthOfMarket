#include "Order.h"

bool Order::operator<(const Order& other) const {
	return price < other.price;
}

bool Order::operator>(const Order& other) const {
	return price > other.price;
}

bool Order::operator==(const Order& other) const {
	return price == other.price && amount == other.amount;
}

bool Order::operator!=(const Order& other) const {
	return price != other.price || amount != other.amount;
}

