#pragma once

#include "Order.h"

#include <map>
#include <vector>
#include <set>
#include <memory>

class OrderBook {
public:

	OrderBook() = default;

	OrderBook(const OrderBook&) = delete;
	OrderBook(OrderBook&&) = delete;
	OrderBook& operator=(const OrderBook&) = delete;
	OrderBook& operator=(OrderBook&&) = delete;

	unsigned int AddOrder(Order::Type type, Order& order);
	bool ChangeAmountOfOrder(unsigned int id, unsigned int new_amount);
	bool DeleteOrder(unsigned int id);

	std::vector<std::tuple<unsigned int, Order::Type, Order*>> GetTopOrders(unsigned int count = 10);
private:
	std::map<unsigned int, Order> asks_;
	std::map<unsigned int, Order> bids_;
	std::set<unsigned int> asks_free_ids_;
	std::set<unsigned int> bids_free_ids_;

	unsigned int AddAsk(Order& order);
	unsigned int AddBid(Order& order);

};

