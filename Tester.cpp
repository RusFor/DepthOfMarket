#include "Tester.h"
#include "Generator.h"

#include <iostream>

using namespace std::literals;

void OrderBookTester::TestAddOrder() {
	OrderBook order_book;
	Order order1(generator_.GenerateOrder());
	Order order2(generator_.GenerateOrder());

	unsigned int id1 = order_book.AddOrder(Order::Type::Ask, order1);
	unsigned int id2 = order_book.AddOrder(Order::Type::Bid, order2);

	bool is_id1_even = id1 >> 1;
	bool is_id2_odd = id2 >> 1;
	if(!is_id1_even) {
		std::cerr << "ID not even : "sv << id1 << '\n';
	}
	if(!is_id2_odd) {
		std::cerr << "ID not odd : "sv << id2 << '\n';
	}

	Order order1_from_order_book = *order_book.GetOrder(id1);
	if(order1 != order1_from_order_book) {
		std::cerr << "Order after adding is not equal to it"sv << id2 << '\n';
	}
}

void OrderBookTester::TestChangeAmountOfOrder() {
	OrderBook order_book;
	Order order(generator_.GenerateOrder());
	unsigned int id = order_book.AddOrder(Order::Type::Ask, order);

	unsigned int newAmount = 10;
	bool result = order_book.ChangeAmountOfOrder(id, newAmount);


}

void OrderBookTester::TestDeleteOrder() {
	OrderBook order_book;
	Order order(generator_.GenerateOrder());
	unsigned int id = order_book.AddOrder(Order::Type::Ask, order);

	bool result = order_book.DeleteOrder(id);


}

void OrderBookTester::TestGetTopOrders() {
	OrderBook order_book;

	unsigned int count = 5;
	auto top_orders = order_book.GetTopOrders(count);

}


