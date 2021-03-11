/**
 * @file inventory.cpp
 * @author Austin Arlitt
 */

#include <vector>
#include "inventory.h"
using namespace std;


/**-------------------------------- display -----------------------------------
 * gathers entire inventory into a sorted vector for output display
 * @return the whole inventory in sorted order
 */
vector<shared_ptr<Item>> Inventory::display() {
    vector<shared_ptr<Item>> stock;
    set<shared_ptr<DVD>, comp>::iterator it;

    // first add comedies
    for(it = comedies.begin(); it != comedies.end(); ++it) {
        stock.push_back(*it);
    }

    // then add dramas
    for(it = dramas.begin(); it != dramas.end(); ++it) {
        stock.push_back(*it);
    }

    // finally add classics
    for(it = classics.begin(); it != classics.end(); ++it) {
        stock.push_back(*it);
    }

    return stock;
}

/**------------------------------- addStock -----------------------------------
 * adds stock of an item to the inventory
 * @param item the item to add to the inventory
 * @param amount the quantity of stock to be added
 * @pre since an item may be constructed with 0 stock or amount of stock, the
 *      convention used here assumes the item passed in has 0 stock, with the
 *      amount int tracking the quantity to be added to the inventory
 */
void Inventory::addStock(Item & item, int amount) {
    // first cast the item to DVD (only DVD movies are used in the project)
    DVD & dvd = dynamic_cast<DVD &>(item);

    // check which genre of movie is on DVD
    Movie* movie = &dvd.getMovie();     // pointer fails to nullptr for following dynamic_cast checks
                                        // whereas a reference fails with an exception, so use pointer
    // check for comedy genre
    ComedyMovie* comedy = dynamic_cast<ComedyMovie*>(movie);
    if(comedy != nullptr) {
        // check if movie is already in inventory
        set<shared_ptr<DVD>, comp>::iterator it;
        it = comedies.find(static_cast<shared_ptr<DVD>>(&dvd));

        // if movie must be added to inventory
        if(it == comedies.end()) {
            dvd.addStock(amount);       // assuming the precondition
            comedies.insert(static_cast<shared_ptr<DVD>>(&dvd));
        }

        // otherwise adjust stock for existing inventory
        else {
            DVD & disk = static_cast<DVD &>(*it->get());
            disk.addStock(amount);
        }
    }

    // check for drama genre
    DramaMovie* drama = dynamic_cast<DramaMovie*>(movie);
    if(drama != nullptr) {
        // check if movie is already in inventory
        set<shared_ptr<DVD>, comp>::iterator it;
        it = dramas.find(static_cast<shared_ptr<DVD>>(&dvd));

        // if movie must be added to inventory
        if(it == dramas.end()) {
            dvd.addStock(amount);       // assuming the precondition
            dramas.insert(static_cast<shared_ptr<DVD>>(&dvd));
        }

            // otherwise adjust stock for existing inventory
        else {
            DVD & disk = static_cast<DVD &>(*it->get());
            disk.addStock(amount);
        }
    }

    // check for classics genre
    ClassicMovie* classic = dynamic_cast<ClassicMovie*>(movie);
    if(classic != nullptr) {
        // check if movie is already in inventory
        set<shared_ptr<DVD>, comp>::iterator it;
        it = classics.find(static_cast<shared_ptr<DVD>>(&dvd));

        // if the movie is already in inventory
        if(it != classics.end()) {
            // look for equivalent classics (i.e. same title, different actor)
            set<shared_ptr<DVD>, comp>::iterator equivIt;
            for(equivIt = classics.begin(); equivIt != classics.end(); ++equivIt) {
                DVD & addedItem = static_cast<DVD &>(*it->get());
                DVD & equivItem = static_cast<DVD &>(*equivIt->get());

                if(addedItem.getTitle() == equivItem.getTitle()) {
                    // add stock for all listings of movie
                    equivItem.addStock(amount);
                }
            }
        }

        //////////////////////////

//        // if movie must be added to inventory
//        if(it == comedies.end()) {
//            dvd.addStock(amount);       // assuming the precondition
//            comedies.insert(static_cast<shared_ptr<DVD>>(&dvd));
//        }
//
//            // otherwise adjust stock for existing inventory
//        else {
//            DVD & disk = static_cast<DVD &>(*it->get());
//            disk.addStock(amount);
//        }

        // additional checks for equivalent entries
    }
}

void Inventory::borrow(Item &) {

}

void Inventory::restock(Item &) {

}
