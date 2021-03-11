/**
 * @file borrow_command.cpp
 * @author Dominic Ewing
 */

#include <utility>	// std::move

#include "borrow_command.h"
#include "rental_system.h"

/**
 * Construct a borrow command object.
 *
 * @param cid The customer id of the customer borrowing the item.
 * @param itm The item the customer wishes to borrow.
 */
BorrowCommand::BorrowCommand(int cid, std::unique_ptr<Item> itm)
	: tx_customer_id{cid}, tx_item{std::move(itm)}
{
}

/**
 * Ask the rental system to execute the borrow command.
 *
 * @param rentalSystem The rental system where the item will be borrowed.
 */
void BorrowCommand::runWith(RentalSystem& rentalSystem)
{
	rentalSystem.borrow(tx_customer_id, *tx_item);
}

/**
 * Get the customer id for the customer borrowing the item.
 *
 * @return The customer id.
 */
int BorrowCommand::customerID() const
{
	return tx_customer_id;
}

/**
 * Get the item the customer is borrowing.
 *
 * @return The item the customer wants to borrow.
 */
Item& BorrowCommand::item() const
{
	return *tx_item;
}
