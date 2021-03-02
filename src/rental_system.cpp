/**
 * @file rental_system.cpp
 * @author Dominic Ewing
 */

#include <utility>	// std::move

#include "rental_system.h"
#include "rental_system_error.h"

/**
 * Construct a rental system object.
 *
 * @param inv The inventory of the rental system.
 * @param clients The clientele of the rental system
 * @param disp The display where rental system output should be sent.
 */
RentalSystem(Inventory inv, Clientele clients, std::unique_ptr<Display> disp)
	: inventory{std::move(inv)},
	customers{std::move(clients)},
	display{std::move(disp)}
{
}

/**
 * Rent an inventory item to a customer.
 *
 * @param command The command object containing the necessary information to
 *                carry out the command.
 */
void RentalSystem::borrow(Transaction command)
{
	try
	{
		auto& customer = customers.findCustomer(command.customerID());
		auto& item = inventory.borrow(command.item());
	}
	catch (const RentalSystemError& error)
	{
		display->reportError(error);
		return;
	}

	customer.borrow(std::move(command), item);
}

/**
 * Return a borrowed item from a customer to the inventory.
 *
 * @param command The command object containing the necessary information to
 *                carry out the command.
 */
void RentalSystem::restock(Transaction command)
{
	try
	{
		auto& customer = customers.findCustomer(command.customerID());
		auto& item = customer.restock(command.item());

		// What is the API to roll back the customer.restock() should
		// inventory.restock() fail?
		inventory.restock(item);
	}
	catch (const RentalSystemError& error)
	{
		display->reportError(error);
		return;
	}
}

/**
 * Display the rental system inventory to the user.
 */
void RentalSystem::inventory()
{
	display->display(inventory.inventory());
}

/**
 * Display the customer's transaction history to the user.
 *
 * @param customerID The id of the desired customer.
 */
void RentalSystem::history(const CustomerID& customerID)
{
	try
	{
		auto& customer = customers.findCustomer(customerID);
	}
	catch (const RentalSystemError& error)
	{
		display->reportError(error);
		return;
	}

	display->display(customer.history());
}
