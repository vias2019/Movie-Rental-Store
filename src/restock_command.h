/**
 * @file restock_command.h
 * @author Dominic Ewing
 */

#ifndef RESTOCK_RESTOCK_H
#define RESTOCK_RESTOCK_H

#include "customer_id.h"
#include "item.h"
#include "transaction.h"

/**
 * Concrete transaction command representing a customer returning an item to
 * the inventory.
 */
class RestockCommand : public Transaction
{
public:
	RestockCommand(CustomerID cid, Item itm);

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
