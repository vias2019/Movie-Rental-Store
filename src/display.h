/**
 * @file display.h
 * @author Dominic Ewing
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>

#include "customer.h"
#include "item.h"
#include "transaction.h"

class Transaction;	// Forward declaration.

/**
 * Abstract base class for objects displaying errors and output to the user.
 */
class Display
{
public:
	virtual ~Display() = default;

	virtual void displayInventory(const std::vector<std::shared_ptr<Item>>& items) const = 0;
	virtual void displayHistory(std::vector<Customer::History> commands) const = 0;
	virtual void displayError(const std::runtime_error& error) const = 0;
};

#endif
