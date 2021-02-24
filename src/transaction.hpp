/**
 * @file command.hpp
 * @author Dominic Ewing
 */

#ifndef RENTAL_SYSTEM_COMMAND_TRANSACTION_HPP
#define RENTAL_SYSTEM_COMMAND_TRANSACTION_HPP

#include "command.hpp"

/**
 * Abstract base class for transaction commands involving the customer borrowing
 * or returning an item.
 */
class Transaction : public Command
{
public:
	virtual void runWith(RentalSystem& rentalSystem) = 0;

	virtual CustomerID customerID() const = 0;
	virtual Item item() const = 0;
};

#endif
