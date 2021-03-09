/**
 * @file borrow_command.h
 * @author Dominic Ewing
 */

#ifndef BORROW_COMMAND_H
#define BORROW_COMMAND_H

#include "customer_id.h"
#include "item.h"
#include "transaction.h"

/**
 * Concrete transaction command representing a customer borrowing an item from
 * the inventory.
 */
class BorrowCommand : public Transaction
{
public:
	BorrowCommand(CustomerID cid, Item itm);

	// Command interface.
	void runWith(RentalSystem& rentalSystem) override;

	// Transaction interface.
	CustomerID customerID() const override;
	Item item() const override;

private:
	CustomerID tx_customer_id;
	Item tx_item;
};

#endif