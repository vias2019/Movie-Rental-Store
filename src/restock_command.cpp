/**
 * @file restock_command.cpp
 * @author Dominic Ewing
 */

#include <utility>	// std::move

#include "restock_command.hpp"

RestockCommand::RestockCommand(CustomerID cid, Item item)
	: customer_id{std::move(cid)}, item{std::move(item)}
{
}

/**
 * Ask the rental system to execute the restock command.
 *
 * @param rentalSystem The rental system where the item will be returned.
 */
void RestockCommand::runWith(RentalSystem& rentalSystem) override
{
}

/**
 * Get the customer id for the customer returning the item.
 *
 * @return The customer id.
 */
CustomerID RestockCommand::customerID() const override
{
	return customer_id;
}

/**
 * Get the item the customer is returning.
 *
 * @return The item the customer wants to return.
 */
Item RestockCommand::item() const override
{
	return item;
}
