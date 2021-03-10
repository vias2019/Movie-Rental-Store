/**
 * @file borrow_command.h
 * @author Dominic Ewing
 */

#ifndef BORROW_COMMAND_H
#define BORROW_COMMAND_H

#include <memory> // unique_ptr

#include "item.h"
#include "transaction.h"

/**
 * Concrete transaction command representing a customer borrowing an item from
 * the inventory.
 */
class BorrowCommand : public Transaction
{
public:
	BorrowCommand(int cid, std::unique_ptr<Item> itm);

	// Command interface.
	void runWith(RentalSystem& rentalSystem) override;

	// Transaction interface.
	int customerID() const override;
	Item& item() const override;

private:
	int tx_customer_id;
	std::unique_ptr<Item> tx_item;
};

#endif
