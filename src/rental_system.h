/**
 * @file rental_system.h
 * @author Dominic Ewing
 */

#ifndef RENTAL_SYSTEM_H
#define RENTAL_SYSTEM_H

#include <memory>	// Use smart pointers for owned memeory.

#include "customer_id.hpp"
#include "transaction.hpp"
#include "display.hpp"

/**
 * Main rental system class coordinating the inventory and customer data stores,
 * output display, and providing the command interface.
 */
class RentalSystem
{
public:
	RentalSystem(Inventory inv, Clientele clients,
	             std::unique_ptr<Display> disp);

	void borrow(Transaction command);
	void restock(Transaction command);
	void inventory();
	void history(const CustomerID& customerID);

private:
	Inventory inventory;
	Clientele customers;

	// Display is abstract. Use unique_ptr to allow polymorphism while still
	// having memory safety.
	std::unique_ptr<Display> display;
};

#endif
