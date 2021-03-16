/**
 * @file rental_system.h
 * @author Dominic Ewing
 */

#ifndef RENTAL_SYSTEM_H
#define RENTAL_SYSTEM_H

#include <memory>   // unique_ptr

#include "display.h"
#include "hashtable.h"
#include "inventory.h"
#include "transaction.h"

class Transaction;  // Forward declaration.

/**
 * Main rental system class coordinating the inventory and customer data stores,
 * output display, and providing the command interface.
 */
class RentalSystem
{
public:
    // Constructor
    RentalSystem(Inventory inv, HashTable clients,
                 std::unique_ptr<Display> disp);

    // Rental system interface
    void borrow(int customerID, DVD& dvd);
    void restock(int customerID, DVD& dvd);
    void inventory();
    void history(int customerID);

private:
    Inventory items;        // The rental system's inventory
    HashTable customers;    // The rental system's customers

    // Display is abstract. Use unique_ptr to allow polymorphism while still
    // having memory safety. This is used to display information and errors
    // to the user.
    std::unique_ptr<Display> display;
};

#endif
