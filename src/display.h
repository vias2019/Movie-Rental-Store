/**
 * @file display.h
 * @author Dominic Ewing
 */

#ifndef RENTAL_SYSTEM_DISPLAY_HPP
#define RENTAL_SYSTEM_DISPLAY_HPP

#include "item.h"
#include "rental_system_error.h"
#include "transaction.h"

/**
 * Abstract base class for objects displaying errors and output to the user.
 */
class Display
{
	virtual void display(const std::vector<Item>& items) const = 0;
	virtual void display(const std::vector<Transaction>& commands) const = 0;
	virtual void displayError(const RentalSystemError& error) const = 0;
};

#endif
