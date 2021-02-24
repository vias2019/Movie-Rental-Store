/**
 * @file command.hpp
 * @author Dominic Ewing
 */

#ifndef RENTAL_SYSTEM_COMMAND_HPP
#define RENTAL_SYSTEM_COMMAND_HPP

/**
 * Abstract base class for all rental system commands.
 */
class Command
{
public:
	virtual void runWith(RentalSystem& rentalSystem) = 0;
};

#endif
