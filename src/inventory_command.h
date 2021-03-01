/**
 * @file inventory_command.h
 * @author Dominic Ewing
 */

#ifndef INVENTORY_COMMAND_H
#define INVENTORY_COMMAND_H

#include "customer_id.h"
#include "item.h"
#include "command.h"

/**
 * Concrete command for reporting the rental system's inventory.
 */
class InventoryCommand : public Command
{
public:
	// Command interface.
	void runWith(RentalSystem& rentalSystem) override;
};

#endif
