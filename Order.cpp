#include "Order.h"

bool Order::operator<(Order& other) {
	return price < other.price;
}

bool Order::operator>(Order& other) {
	return price > other.price;
}
