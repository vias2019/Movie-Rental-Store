/**
 * Assignment 4 - movie rental system
 * This file provides the main method that drives the program.
 *
 * @file main.cpp
 * @author Dominic Ewing
 */

#include "command_file.h"
#include "console_display.h"
#include "customer.h"
#include "customer_file.h"
#include "hashtable.h"
#include "inventory_file.h"
#include "rental_system.h"

// Define the default input file locations
#ifndef INVENTORY_FILE_LOCATION
#define INVENTORY_FILE_LOCATION data4movies.txt
#endif

#ifndef CUSTOMER_FILE_LOCATION
#define CUSTOMER_FILE_LOCATION data4customers.txt
#endif

#ifndef COMMAND_FILE_LOCATION
#define COMMAND_FILE_LOCATION data4commands.txt
#endif

/**
 * Main - create the system's main objects and drives the program
 */
int main()
{
    // Build the display.
    ConsoleDisplay display{};

    // Build the inventory and report errors.
    InventoryFile inventoryFile{"data/movies.txt"};
    Inventory inventory = inventoryFile.inventory();
    const auto inventoryErrors = inventoryFile.errors();
    std::for_each(inventoryErrors.cbegin(), inventoryErrors.cend(),
        [&display](const auto& error) {
            display.displayError(*error);
    });

    // Build the client list.
    CustomerFile customerFile;
    HashTable customers;
    customerFile.readFile("data/customers.txt", customers);

    // Build the rental system object.
    RentalSystem rentalSystem{
        inventory, customers, std::unique_ptr<Display>{new ConsoleDisplay{}}};

    // Build the command list and report errors.
    CommandFile command_file{"data/commands.txt"};
    auto commands = command_file.commands();
    const auto command_errors = command_file.errors();
    std::for_each(command_errors.cbegin(), command_errors.cend(),
        [&display](const auto& error) {
            display.displayError(*error);
    });

    // Run the commands.
    std::for_each(commands.cbegin(), commands.cend(),
        [&rentalSystem](const auto& command) {
            command->runWith(rentalSystem);
    });
    
    return 0;
}

