/**
 * @file inventory_command.cpp
 * @author Dominic Ewing
 */

#include "inventory_command.h"

/**
 * Ask the rental system to report it's inventory to the user.
 *
 * @param rentalSystem The rental system whose inventory should be reported.
 */
void InventoryCommand::runWith(RentalSystem& rentalSystem) override
{
	rentalSystem.inventory();
}
