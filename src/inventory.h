/**
 * @file inventory.h
 * @author Austin Arlitt
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
#include "dvd.h"
#include "movie.h"
#include "comedy_movie.h"
#include "drama_movie.h"
#include "classic_movie.h"
#include <set>
#include <memory>


/**
 * A class for managing the inventory of a movie rental store
 */
class Inventory {
public:
    Inventory();                        // default constructor, creates empty inventory
    ~Inventory();                       // destructor
    std::vector<Item &> & display();    // gathers all inventory items into a sorted vector
    void addStock(Item &, int);         // adds stock of an item to the inventory
    void borrow(Item &);                // attempts to check out an item for a customer
    void restock(Item &);               // returns borrowed item from a customer to inventory

private:
    std::set<std::shared_ptr<Item>> comedies;          // the comedy movies in the inventory
    std::set<std::shared_ptr<Item>> dramas;            // the drama movies in the inventory
    std::set<std::shared_ptr<Item>> classics;          // the classic movies in the inventory
};

#endif
