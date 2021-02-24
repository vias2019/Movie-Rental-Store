/**
 * @file inventory_command.hpp
 * @author Dominic Ewing
 */

#ifndef RENTAL_SYSTEM_COMMAND_INVENTORY_HPP
#define RENTAL_SYSTEM_COMMAND_INVENTORY_HPP

#include "customer_id.hpp"
#include "item.hpp"
#include "command.hpp"

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
