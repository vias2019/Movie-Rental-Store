/**
 * @file borrow_command.cpp
 * @author Dominic Ewing
 */

#include <utility>	// std::move

#include "borrow_command.hpp"

BorrowCommand::BorrowCommand(CustomerID cid, Item item)
	: customer_id{std::move(cid)}, item{std::move(item)}
{
}

/**
 * Ask the rental system to execute the borrow command.
 *
 * @param rentalSystem The rental system where the item will be borrowed.
 */
void BorrowCommand::runWith(RentalSystem& rentalSystem) override
{
}

/**
 * Get the customer id for the customer borrowing the item.
 *
 * @return The customer id.
 */
CustomerID BorrowCommand::customerID() const override
{
	return customer_id;
}

/**
 * Get the item the customer is borrowing.
 *
 * @return The item the customer wants to borrow.
 */
Item BorrowCommand::item() const override
{
	return item;
}
