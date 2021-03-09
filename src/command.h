/**
 * @file command.h
 * @author Dominic Ewing
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "rental_system.h"

/**
 * Abstract base class for all rental system commands.
 */
class Command
{
public:
	/**
	 * Run the command with the specified rental system.
	 *
	 * @param rentalSystem The rental system with which to run the command.
	 */
	virtual void runWith(RentalSystem& rentalSystem) = 0;

	// Ensure inheriting classes call their own destructors
	virtual ~Command() = default;
};

#endif
