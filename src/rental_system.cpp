/**
 * @file rental_system.cpp
 * @author Dominic Ewing
 */

#include <utility>  // std::move

#include "rental_system.h"

/**
 * Constructor - Construct a rental system object.
 *
 * @param inv The inventory of the rental system.
 * @param clients The clientele of the rental system
 * @param disp The display where rental system output should be sent.
 */
RentalSystem::RentalSystem(
    Inventory inv, HashTable clients, std::unique_ptr<Display> disp)
    : items{std::move(inv)},
    customers{std::move(clients)},
    display{std::move(disp)}
{
}

/**
 * borrow - Rent an inventory item to a customer.
 *
 * At the moment only dvds are supported, when more item types are added, please
 * update this to accept other item types as well.
 *
 * @param customerID The customer id of the borrowing customer
 * @param dvd The dvd item being borrowed
 */
void RentalSystem::borrow(int customerID, DVD& dvd)
{
    try
    {
        // This throws an exectption for an invalid customer id.
        (void) customers.findCustomer(customerID);

        // Get the actual item from the inventory so that all the movie
        // information is stored in the customer history, and we know
        // it is valid.
        DVD& inventory_item = items.lookup(dvd);

        // Perform the borrow operations.
        items.borrow(inventory_item);
        customers.borrow(customerID, inventory_item);
    }
    catch (const std::runtime_error& error)
    {
        display->displayError(error);
    }

}

/**
 * restock - Return a borrowed item from a customer to the inventory.
 *
 * At the moment only dvds are supported, when more item types are added, please
 * update this to accept other item types as well.
 *
 * @param customerID The customer id of the customer returning the item
 * @param dvd The dvd item being returned
 */
void RentalSystem::restock(int customerID, DVD& dvd)
{
    try
    {
        // This throws an exectption for an invalid customer id.
        (void) customers.findCustomer(customerID);

        // Get the actual item from the inventory so that we know the
        // item is valid.
        DVD& inventory_item = items.lookup(dvd);

        // Perform the restock operations.
        customers.restock(customerID, inventory_item);
        items.restock(inventory_item);
    }
    catch (const std::runtime_error& error)
    {
        display->displayError(error);
    }
}

/**
 * inventory - Display the rental system inventory to the user.
 */
void RentalSystem::inventory()
{
    display->displayInventory(items.display());
}

/**
 * history - Display a customer's transaction history to the user.
 *
 * @param customerID The id of the desired customer.
 */
void RentalSystem::history(int customerID)
{
    try
    {
        auto customer = customers.findCustomer(customerID);
        display->displayHistory(customerID, customer.history);
    }
    catch (const std::runtime_error& error)
    {
        display->displayError(error);
    }
}
