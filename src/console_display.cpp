/**
 * @file console_display.cpp
 * @author Dominic Ewing
 */

#include <algorithm>	// std::for_each
#include <iostream>	// std::cout and std::cerr

#include "console_display.h"

/**
 * Display the rental system inventory to stdout.
 *
 * @param items The list of items in the rental sytsem inventory in sorted order.
 */
void ConsoleDisplay::displayInventory(const std::vector<std::shared_ptr<Item>>& items) const
{
	std::cout << '\n';
	std::cout << "Current Rental System Inventory:\n";
	std::cout << "--------------------------------\n";
	std::for_each(std::cbegin(items), std::cend(items), [](const auto& item) {
		std::cout << item->toString() << '\n';
	});
	std::cout << '\n';
}

/**
 * Display a customer's transaction history to stdout.
 *
 * @param customerID The id number of the customer.
 * @param transactions The list of transactions in the customer's history.
 */
void ConsoleDisplay::displayHistory(int customerID, std::vector<Customer::History> transactions) const
{
	std::cout << '\n';
	std::cout << "Transaction history for customer " << customerID << ":\n";
	std::cout << "--------------------------------------\n";
	std::for_each(std::cbegin(transactions), std::cend(transactions), [](const auto& transaction) {
		switch (transaction.type) {
		case 'b': case 'B':
			std::cout << "Borrowed: ";
			break;
		case 'r': case 'R':
			std::cout << "Returned: ";
			break;
		default:
			throw std::runtime_error("Invalid transaction code");
		}
		std::cout << transaction.movie->getMovie().toString() << '\n';
	});

	if (transactions.empty())
	{
		std::cout << "None\n";
	}
	std::cout << '\n';
}

/**
 * Display an error message to stderr.
 *
 * @param error The error object whose message will be displayed to the user.
 */
void ConsoleDisplay::displayError(const std::runtime_error& error) const
{
	std::cerr << "ERROR: ";
	std::cerr << error.what() << '\n';
}
