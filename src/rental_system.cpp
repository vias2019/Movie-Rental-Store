/**
 * @file rental_system.cpp
 * @author Dominic Ewing
 */

#include <utility>	// std::move

#include "rental_system.h"

/**
 * Construct a rental system object.
 *
 * @param inv The inventory of the rental system.
 * @param clients The clientele of the rental system
 * @param disp The display where rental system output should be sent.
 */
RentalSystem::RentalSystem(Inventory inv, HashTable clients, std::unique_ptr<Display> disp)
	: items{std::move(inv)},
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
void RentalSystem::borrow(int customerID, DVD& dvd)
{
	try
	{
		// throws std::bad_cast if this fails.
//		DVD& dvd = dynamic_cast<DVD&>(item);
		items.borrow(dvd);
		customers.borrow(customerID, dvd);
	}
	catch (const std::runtime_error& error)
	{
		display->displayError(error);
	}

}

/**
 * Return a borrowed item from a customer to the inventory.
 *
 * @param command The command object containing the necessary information to
 *                carry out the command.
 */
void RentalSystem::restock(int customerID, DVD& dvd)
{
	try
	{
		// throws std::bad_cast if this fails.
//		DVD& dvd = dynamic_cast<DVD&>(item);
		customers.restock(customerID, dvd);
		items.restock(dvd);
	}
	catch (const std::runtime_error& error)
	{
		display->displayError(error);
	}
}

/**
 * Display the rental system inventory to the user.
 */
void RentalSystem::inventory()
{
	display->displayInventory(items.display());
}

/**
 * Display the customer's transaction history to the user.
 *
 * @param customerID The id of the desired customer.
 */
void RentalSystem::history(int customerID)
{
	try
	{
		auto customer = customers.findCustomer(customerID);
		display->displayHistory(customerID, customer.history);
	}
	catch (const std::runtime_error& error)
	{
		display->displayError(error);
	}
}
