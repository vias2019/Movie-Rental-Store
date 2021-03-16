/**
 * @file display.h
 * @author Dominic Ewing
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>   // vector

#include "customer.h"
#include "item.h"
#include "transaction.h"

class Transaction;  // Forward declaration.

/**
 * Abstract base class for objects displaying errors and output to the user.
 */
class Display
{
public:
    // Ensure subclasses call their own destructor
    virtual ~Display() = default;

    // Display interface
    /**
     * displayInventory - Display the system's inventory to the user.
     *
     * @param items A list of all the items in the inventory
     */
    virtual void displayInventory(
        const std::vector<std::shared_ptr<Item>>& items) const = 0;

    /**
     * displayHistory - Display a cusomer's transaction history to the user.
     *
     * @param customerID The customer's id number
     * @param transactions A list of the customer's transactions
     */
    virtual void displayHistory(
        int customerID, std::vector<Customer::History> transactions) const = 0;

    /**
     * displayError - Display an error message to the user
     *
     * @param error The error to be displayed.
     */
    virtual void displayError(const std::runtime_error& error) const = 0;
};

#endif
