#include "OrderBook.h"
#include "Order.h"

#include <algorithm>
unsigned int OrderBook::AddOrder(Order::Type type, Order& order) {
	unsigned int id = 0;
	if(type == Order::Type::Ask) {
		id = AddAsk(order);
	} else {
		id = AddBid(order);
	}
	return id;
}

bool OrderBook::ChangeAmountOfOrder(unsigned int id, unsigned int new_amount) {
	std::map<unsigned int, Order>::iterator order;
	if(id >> 1 == 0) {
		order = asks_.find(id);
		if(order == asks_.end()) {
			return false;
		}
	} else {
		order = bids_.find(id);
		if(order == bids_.end()) {
			return false;
		}
	}
	order->second.amount = new_amount;
	return true;
}

bool OrderBook::DeleteOrder(unsigned int id) {
	if(id >> 1 == 0) {
		if(!asks_.contains(id)) {
			return false;
		}
		asks_.erase(id);
		asks_free_ids_.insert(id);
	} else {
		if(!bids_.contains(id)) {
			return false;
		}
		bids_.erase(id);
		bids_free_ids_.insert(id);
	}
	return true;
}

const Order* OrderBook::GetOrder(unsigned int id) const {
	if(id >> 1 == 0) {
		if(asks_.contains(id)) {
			return &asks_.at(id);
		}
	} else {
		if(bids_.contains(id)) {
			return &bids_.at(id);
		}
	}
	return nullptr;
}

std::vector<std::tuple<unsigned int, Order::Type, const Order*>> OrderBook::GetTopOrders(unsigned int count) const {
	auto asks = GetSortedOrders(Order::Type::Ask);
	auto bids = GetSortedOrders(Order::Type::Bid);

	std::vector<std::tuple<unsigned int, Order::Type, const Order*>> output;
	output.reserve(count);

	for(size_t i = 0; i < count; ++i) {
		if(asks.size() > i) {
			output.push_back(std::make_tuple(asks[i].first, Order::Type::Ask, asks[i].second));
			if(bids.size() > i) {
				output.push_back(std::make_tuple(bids[i].first, Order::Type::Bid, bids[i].second));
				++i;
			}
		} else if(bids.size() > i) {
			output.push_back(std::make_tuple(bids[i].first, Order::Type::Bid, bids[i].second));
		}
	}
	return output;
}

unsigned int OrderBook::AddAsk(Order& order) {
	unsigned int id = 0;
	if(!asks_free_ids_.empty()) {
		id = *asks_free_ids_.begin();
		asks_free_ids_.erase(id);
	} else if(!asks_.empty()) {
		id = asks_.rbegin()->first + STEP;
	}
	asks_.emplace(id, std::move(order));
	return id;
}

unsigned int OrderBook::AddBid(Order& order) {
	unsigned int id = 1;
	if(!bids_free_ids_.empty()) {
		id = *bids_free_ids_.begin();
		bids_free_ids_.erase(id);
	} else if(!bids_.empty()) {
		id = bids_.rbegin()->first + STEP;
	}
	bids_.emplace(id, std::move(order));
	return id;
}

std::vector<std::pair<unsigned int, const Order*>> OrderBook::GetSortedOrders(Order::Type type) const {
	std::vector<std::pair<unsigned int, const Order*>> output;
	if(type == Order::Type::Ask) {
		output.reserve(asks_.size());
		for(auto& [id, order] : asks_) {
			output.push_back(std::make_pair(id, &order));
		}
		std::sort(output.begin(), output.end(), [](auto& left, auto& right) {
			return *left.second < *right.second;
		});
	} else {
		output.reserve(bids_.size());
		for(auto& [id, order] : bids_) {
			output.push_back(std::make_pair(id, &order));
		}
		std::sort(output.begin(), output.end(), [](auto& left, auto& right) {
			return *left.second > *right.second;
		});
	}
	return output;
}
