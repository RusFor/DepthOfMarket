#include "Tester.h"
#include "Generator.h"

#include <iostream>

using namespace std::literals;

std::ostream& operator<<(std::ostream& out, const Order& order) {
	out << "amount: "sv << order.amount << '\n';
	out << "price: "sv << order.price << '\n';
	return out;
}

void OrderBookTester::TestAddOrder() { 
	std::cerr << "======================\nTestAddOrder\n"sv;
	OrderBook order_book;
	Order order1(generator_.GenerateOrder());
	Order order2(generator_.GenerateOrder());

	unsigned int id1 = order_book.AddOrder(Order::Type::Ask, order1);
	unsigned int id2 = order_book.AddOrder(Order::Type::Bid, order2);

	bool is_id1_even = (id1 & 1) == 0;
	bool is_id2_odd = (id2 & 1) == 1;
	if(is_id1_even == false) {
		std::cerr << "ID not even : "sv << id1 << '\n';
	}
	if(is_id2_odd == false) {
		std::cerr << "ID not odd : "sv << id2 << '\n';
	}
	auto order1_ptr = order_book.GetOrder(id1);
	if(order1_ptr == nullptr) {
		std::cerr << "id1 is not id for order: " << id1 << '\n';
	}
	auto order2_ptr = order_book.GetOrder(id2);
	if(order2_ptr == nullptr) {
		std::cerr << "id2 is not id for order: " << id2 << '\n';
	}

	if(order1_ptr && order2_ptr) {
		Order order1_from_order_book = *order1_ptr;
		CompareTwoOrders(order1, order1_from_order_book);

		Order order2_from_order_book = *order2_ptr;
		CompareTwoOrders(order2, order2_from_order_book);
	}

}

void OrderBookTester::TestChangeAmountOfOrder() {
	std::cerr << "======================\nTestChangeAmountOfOrder\n"sv;
	OrderBook order_book;
	Order order(generator_.GenerateOrder());
	unsigned int id = order_book.AddOrder(Order::Type::Ask, order);
	//it can overflow, but it ok.
	unsigned int newAmount = order.amount + 1;
	order.amount += 1;
	bool result = order_book.ChangeAmountOfOrder(id, newAmount);
	if(!result) {
		std::cerr << "ChangeAmountOfOrder is failed!\n"sv;
	}

	Order order_getted = *order_book.GetOrder(id);
	CompareTwoOrders(order, order_getted);
}

void OrderBookTester::TestDeleteOrder() {
	std::cerr << "======================\nTestDeleteOrder\n"sv;
	OrderBook order_book;
	Order order(generator_.GenerateOrder());
	unsigned int id = order_book.AddOrder(Order::Type::Ask, order);

	bool result = order_book.DeleteOrder(id);
	if(!result) {
		std::cerr << "DeleteOrder is failed!\n"sv;
	}
	auto order_deleted = order_book.GetOrder(id);
	if(order_deleted != nullptr) {
		std::cerr << "Order was not deleted!\n"sv;
	}
}

void OrderBookTester::TestGetTopOrders() {
	std::cerr << "======================\nTestGetTopOrders\n"sv;
	OrderBook order_book;
	unsigned int count = 10;
	std::vector <std::tuple<unsigned int, Order::Type, const Order*>> orders;
	for(size_t i = 0; i < count; ++i) {
		auto type = generator_.GenerateOrderType();
		auto order = generator_.GenerateOrder();
		unsigned int id = order_book.AddOrder(type, order);
		const Order* order_ptr = order_book.GetOrder(id);
		orders.push_back(std::make_tuple(id, type, order_ptr));
	}
	auto top_orders = order_book.GetTopOrders(count);

	for(const auto& [id_old, type_old, order_old] : orders) {
		auto it = std::find_if(top_orders.begin(), top_orders.end(), [&](auto order_top ) {
			const auto& [id_new, type_new, order_new] = order_top;
			return id_new == id_old && type_new == type_old && order_new == order_old;
		});
		if(it != top_orders.end()) {
			top_orders.erase(it);

		} else {
			std::cerr << "Order_old does not appear to be in top_orders!:\n";
		}
	}
}

void OrderBookTester::CompareTwoOrders(const Order& order1, const Order& order2) const {
	if(order1 != order2) {
		std::cerr << "Order after adding is not equal to itself: \n "sv
			<< order1 << order2 << '\n';
	}
}


