cmake_minimum_required(VERSION 3.16)
project(Movie_Rental_Store)

add_executable(Movie_Rental_Store
        src/borrow_command.cpp
        src/command_file.cpp
	src/customer.cpp
        src/customer_file.cpp
	src/hashtable.cpp
        src/history_command.cpp
        src/inventory_command.cpp
        src/inventory_file.cpp
	src/main.cpp
        src/rental_system.cpp
        src/restock_command.cpp)
target_compile_options(Movie_Rental_Store PRIVATE -Wall -Wextra -Wpedantic -Wshadow -g)
target_compile_features(Movie_Rental_Store PRIVATE cxx_std_17)
