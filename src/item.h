/**
 * @file item.h
 * @author Austin Arlitt
 */

#ifndef ITEM_H
#define ITEM_H


/**
 * Abstract base class for items stocked in the inventory
 */
class Item {
public:
    virtual void addStock(int) = 0;     // adds total stock to inventory
    virtual void borrow() = 0;          // attempts to check out item for a customer, decreasing stock
    virtual void restock() = 0;         // returns a borrowed item, increasing stock
};

#endif
