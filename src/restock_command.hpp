/**
 * @file restock_command.hpp
 * @author Dominic Ewing
 */

#ifndef RENTAL_SYSTEM_COMMAND_RESTOCK_HPP
#define RENTAL_SYSTEM_COMMAND_RESTOCK_HPP

#include "customer_id.hpp"
#include "item.hpp"
#include "transaction.hpp"

/**
 * Concrete transaction command representing a customer returning an item to
 * the inventory.
 */
class RestockCommand : public Transaction
{
public:
	RestockCommand(CustomerID cid, Item item);

	// Command interface.
	void runWith(RentalSystem& rentalSystem) override;

	// Transaction interface.
	CustomerID customerID() const override;
	Item item() const override;

private:
	CustomerID customer_id;
	Item item;
};

#endif
