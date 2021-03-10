/**
 * @file restock_command.cpp
 * @author Dominic Ewing
 */

#include <utility>	// std::move

#include "restock_command.h"

/**
 * Construct a restock command object.
 *
 * @param cid The customer id of the customer returning the item.
 * @param itm The item being returned by the customer.
 */
RestockCommand::RestockCommand(CustomerID cid, std::shared_ptr<Item> itm)
	: tx_customer_id{std::move(cid)}, tx_item{std::move(itm)}
{
}

/**
 * Ask the rental system to execute the restock command.
 *
 * @param rentalSystem The rental system where the item will be returned.
 */
void RestockCommand::runWith(RentalSystem& rentalSystem) override
{
	rentalSystem.restock(*this);
}

/**
 * Get the customer id for the customer returning the item.
 *
 * @return The customer id.
 */
CustomerID RestockCommand::customerID() const override
{
	return tx_customer_id;
}

/**
 * Get the item the customer is returning.
 *
 * @return The item the customer wants to return.
 */
Item& RestockCommand::item() const
{
	return *tx_item;
}
