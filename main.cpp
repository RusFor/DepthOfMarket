#include <iostream>
#include <cassert>


#include "OrderBook.h"
#include "Tester.h"
#include "Generator.h"


using namespace std::literals;


int main() {
	OrderBookTester tester;
	tester.TestAddOrder();
	tester.TestChangeAmountOfOrder();
	tester.TestDeleteOrder();
	tester.TestGetTopOrders();
}

