/**
 * @file rental_system.h
 * @author Dominic Ewing
 */

#ifndef RENTAL_SYSTEM_H
#define RENTAL_SYSTEM_H

#include <memory>	// Use smart pointers for owned memeory.

#include "customer_id.h"
#include "hashtable.h"
#include "inventory.h"
#include "transaction.h"
#include "display.h"

class Transaction;	// Forward declaration.

/**
 * Main rental system class coordinating the inventory and customer data stores,
 * output display, and providing the command interface.
 */
class RentalSystem
{
public:
	RentalSystem(Inventory inv, HashTable clients,
	             std::unique_ptr<Display> disp);

	void borrow(Transaction& command);
	void restock(Transaction& command);
	void inventory();
	void history(int customerID);

private:
	Inventory items;
	HashTable customers;

	// Display is abstract. Use unique_ptr to allow polymorphism while still
	// having memory safety.
	std::unique_ptr<Display> display;
};

#endif
