cmake_minimum_required(VERSION 3.16)
project(Movie_Rental_Store)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(Movie_Rental_Store
        src/Assignment4.cpp
        src/borrow_command.cpp
        src/borrow_command.h
        src/classic_movie.h
        src/comedy_movie.h
        src/command.h
        src/command_file.cpp
        src/command_file.h
        src/Customer.h
        src/customer_file.cpp
        src/customer_file.h
        src/customer_id.h
        src/display.h
        src/drama_movie.h
        src/dvd.h
        src/history_command.cpp
        src/history_command.h
        src/inventory.h
        src/inventory_command.cpp
        src/inventory_command.h
        src/inventory_file.cpp
        src/inventory_file.h
        src/item.h
        src/movie.h
        src/rental_system.cpp
        src/rental_system.h
        src/rental_system_error.h
        src/restock_command.cpp
        src/restock_command.h
        src/transaction.h)
