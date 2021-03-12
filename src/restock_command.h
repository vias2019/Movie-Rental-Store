/**
 * @file restock_command.h
 * @author Dominic Ewing
 */

#ifndef RESTOCK_RESTOCK_H
#define RESTOCK_RESTOCK_H

#include <memory>	// shared_ptr

#include "dvd.h"
#include "transaction.h"

/**
 * Concrete transaction command representing a customer returning an item to
 * the inventory.
 */
class RestockCommand : public Transaction
{
public:
	RestockCommand(int cid, std::shared_ptr<DVD> itm);

	// Command interface.
	void runWith(RentalSystem& rentalSystem) override;

	// Transaction interface.
	int customerID() const override;
	DVD& item() const override;

private:
	int tx_customer_id;
	std::shared_ptr<DVD> tx_item;
};

#endif
