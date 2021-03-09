/**
 * @file borrow_command.cpp
 * @author Dominic Ewing
 */

#include <utility>	// std::move

#include "borrow_command.h"

/**
 * Construct a borrow command object.
 *
 * @param cid The customer id of the customer borrowing the item.
 * @param itm The item the customer wishes to borrow.
 */
BorrowCommand::BorrowCommand(CustomerID cid, Item itm)
	: tx_customer_id{std::move(cid)}, tx_item{std::move(itm)}
{
}

/**
 * Ask the rental system to execute the borrow command.
 *
 * @param rentalSystem The rental system where the item will be borrowed.
 */
void BorrowCommand::runWith(RentalSystem& rentalSystem) override
{
	rentalSystem.borrow(*this);
}

/**
 * Get the customer id for the customer borrowing the item.
 *
 * @return The customer id.
 */
CustomerID BorrowCommand::customerID() const override
{
	return tx_customer_id;
}

/**
 * Get the item the customer is borrowing.
 *
 * @return The item the customer wants to borrow.
 */
Item BorrowCommand::item() const override
{
	return tx_item;
}
