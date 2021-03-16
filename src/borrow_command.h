/**
 * @file borrow_command.h
 * @author Dominic Ewing
 */

#ifndef BORROW_COMMAND_H
#define BORROW_COMMAND_H

#include <memory> // unique_ptr

#include "dvd.h"
#include "transaction.h"

/**
 * Concrete transaction command representing a customer borrowing an item from
 * the inventory.
 */
class BorrowCommand : public Transaction
{
public:
    // Constructor
    BorrowCommand(int cid, std::unique_ptr<DVD> itm);

    // Command interface
    void runWith(RentalSystem& rentalSystem) override;

    // Transaction interface
    int customerID() const override;
    DVD& item() const override;

private:
    int tx_customer_id;             // The customer id
    std::unique_ptr<DVD> tx_item;   // The borrowed item
};

#endif
