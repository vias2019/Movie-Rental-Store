/**
 * @file restock_command.cpp
 * @author Dominic Ewing
 */

#include <utility>	// std::move

#include "rental_system.h"
#include "restock_command.h"

/**
 * Construct a restock command object.
 *
 * @param cid The customer id of the customer returning the item.
 * @param itm The item being returned by the customer.
 */
RestockCommand::RestockCommand(int cid, std::shared_ptr<DVD> itm)
	: tx_customer_id{cid}, tx_item{std::move(itm)}
{
}

/**
 * Ask the rental system to execute the restock command.
 *
 * @param rentalSystem The rental system where the item will be returned.
 */
void RestockCommand::runWith(RentalSystem& rentalSystem)
{
	rentalSystem.restock(tx_customer_id, *tx_item);
}

/**
 * Get the customer id for the customer returning the item.
 *
 * @return The customer id.
 */
int RestockCommand::customerID() const
{
	return tx_customer_id;
}

/**
 * Get the item the customer is returning.
 *
 * @return The item the customer wants to return.
 */
DVD& RestockCommand::item() const
{
	return *tx_item;
}
