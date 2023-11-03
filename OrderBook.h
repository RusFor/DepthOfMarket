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
	const Order* GetOrder(unsigned int id) const;
	std::vector<std::tuple<unsigned int, Order::Type, const Order*>> GetTopOrders(unsigned int count = 10) const;
private:
	std::map<unsigned int, Order> asks_;
	std::map<unsigned int, Order> bids_;
	std::set<unsigned int> asks_free_ids_;
	std::set<unsigned int> bids_free_ids_;

	const unsigned int STEP = 2;
	
	unsigned int AddAsk(Order& order);
	unsigned int AddBid(Order& order);
	std::vector<std::pair<unsigned int, const Order*>> GetSortedOrders(Order::Type type) const;
};

