// Assignment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "command_file.h"
#include "console_display.h"
#include "customer.h"
#include "customer_file.h"
#include "hashtable.h"
#include "inventory_file.h"
#include "rental_system.h"

using namespace std;

int main()
{
	/*
   //======================= Viktoriya's tests======================================================
   CustomerFile Nova;
   
   HashTable M;
   Nova.readFile("data4customers.txt", M);
   M.insert(6, "Vika", "Gri");
   M.insert(8, "Dasha", "Mo");
   Customer v = M.findCustomer(3);
   int size = M.getSize();
   DVD movie1;
   DVD movie2;

   M.borrow(6, movie1);
   M.borrow(6, movie2);
  //M.restock(6, movie1);
  // cout << "Print quantity: " << M.checkQuantity(6, movie1) << endl;
   M.printTransactions(6);
 
   //M.deleteData(3);
   //=================================================================================================
   std::cout << "Hello World!\n";
   */

	// Build the display.
	ConsoleDisplay display{};

	// Build the inventory and report errors.
	InventoryFile inventoryFile{"data/movies.txt"};
	Inventory inventory = inventoryFile.inventory();
	const auto inventoryErrors = inventoryFile.errors();
	std::for_each(inventoryErrors.cbegin(), inventoryErrors.cend(), [&display](const auto& error) {
		display.displayError(*error);
	});

	// Build the clientele and report errors.
	// TODO report errors
	CustomerFile customerFile;
	HashTable customers;
	customerFile.readFile("data/customers.txt", customers);

	// Build the rental system object.
	RentalSystem rentalSystem{inventory, customers, std::unique_ptr<Display>{&display}};

	// Build the command list and report errors.
	CommandFile command_file{"data/commands.txt"};
	auto commands = command_file.commands();
	const auto command_errors = command_file.errors();
	std::for_each(command_errors.cbegin(), command_errors.cend(), [&display](const auto& error) {
		display.displayError(*error);
	});

	// Run the commands.
	std::for_each(commands.cbegin(), commands.cend(), [&rentalSystem](const auto& command) {
		command->runWith(rentalSystem);
	});
	


	return 0;
}

