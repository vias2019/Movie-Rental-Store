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
    std::vector<shared_ptr<Item>> display();        // gathers all inventory items into a sorted vector
    void addStock(Item &, int);                     // adds stock of an item to the inventory
    void borrow(Item &);                            // attempts to check out an item for a customer
    void restock(Item &);                           // returns borrowed item from a customer to inventory

private:
    // comparison operator for ordering inventory sets
    struct comp {
        bool operator()(const shared_ptr<DVD> a, const shared_ptr<DVD> b) const {
            return a->compare(*b) < 0;
        }
    };

    std::set<std::shared_ptr<DVD>, comp> comedies;          // the comedy movies in the inventory
    std::set<std::shared_ptr<DVD>, comp> dramas;            // the drama movies in the inventory
    std::set<std::shared_ptr<DVD>, comp> classics;          // the classic movies in the inventory
};

#endif
