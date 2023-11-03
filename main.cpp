#include <iostream>
#include <cassert>


#include "OrderBook.h"
#include "Tester.h"
#include "Generator.h"


using namespace std::literals;

static void Test1() {
	std::cout << "Test1: "sv;
	OrderBook dom;
	Tester tester(dom);
	std::cout << "OK\n"sv;
}

static void Test2() {
	std::cout << "Test2: "sv;
	OrderBook dom;
	Tester tester(dom);
	std::cout << "OK\n"sv;
}

static void Test3() {
	std::cout << "Test3: "sv;
	OrderBook dom;
	Tester tester(dom);
	std::cout << "OK\n"sv;
}
int main() {
	Test1();
	Test2();
}

