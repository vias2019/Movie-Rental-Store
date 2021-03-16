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
     * cusotmerID - Get the customer id of the customer involved in the
     *              transaction.
     *
     * @return The customer id of the customer involved in the transaction.
     */
    virtual int customerID() const = 0;

    /**
     * item - Get the item involved in the transaction.
     *
     * @return The item involved in the transaction.
     */
    virtual DVD& item() const = 0;
};

#endif
