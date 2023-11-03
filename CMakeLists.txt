cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(OrderBook)

set(CMAKE_CXX_STANDARD 20)
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(
        CMAKE_CXX_FLAGS_DEBUG
        "${CMAKE_CXX_FLAGS_DEBUG} /JMC"
    )
else()
    set(
        CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -pthread -Wall -Wextra -pedantic -Wno-unused-parameter -Wno-implicit-fallthrough"
    )
endif()

add_executable(${PROJECT_NAME} 
    main.cpp
    OrderBook.cpp
    OrderBook.h
    Order.cpp
    Order.h
    Generator.cpp
    Generator.h
    Tester.cpp
    Tester.h
	CMakeLists.txt
)

set_directory_properties(PROPERTIES VS_STARTUP_PROJECT ${PROJECT_NAME})