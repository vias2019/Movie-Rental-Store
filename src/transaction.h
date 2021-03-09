/**
 * @file transaction.h
 * @author Dominic Ewing
 */

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "command.h"

/**
 * Abstract base class for transaction commands involving the customer borrowing
 * or returning an item.
 */
class Transaction : public Command
{
public:
	/**
	 * Get the customer id of the customer involved in the transaction.
	 *
	 * @return The customer id of the customer involved in the transaction.
	 */
	virtual CustomerID customerID() const = 0;

	/**
	 * Get the item involved in the transaction.
	 *
	 * @return The item involved in the transaction.
	 */
	virtual Item item() const = 0;
};

#endif
