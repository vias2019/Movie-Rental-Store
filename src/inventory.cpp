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
void Inventory::addStock(const DVD & dvd, int amount) {
    // first convert the DVD reference to shared_ptr
    shared_ptr<DVD> dvd_ptr = make_shared<DVD>(dvd);
    dvd_ptr->resetStock();      // ensures the precondition

    // check which genre of movie is on DVD
    Movie* movie = &dvd_ptr->getMovie();    // pointer fails to nullptr for following dynamic_cast checks
                                            // whereas a reference fails with an exception, so use pointer
    // check for comedy genre
    ComedyMovie* comedy = dynamic_cast<ComedyMovie*>(movie);
    if(comedy != nullptr) {
        // check if movie is already in inventory
        set<shared_ptr<DVD>, comp>::iterator it;
        it = comedies.find(dvd_ptr);

        // if movie must be added to inventory
        if(it == comedies.end()) {
            dvd_ptr->addStock(amount);       // assuming the precondition
            comedies.insert(dvd_ptr);
        }

        // otherwise adjust stock for existing inventory
        else {
            it->get()->addStock(amount);
//            DVD & disk = static_cast<DVD &>(*it->get());
//            disk.addStock(amount);
        }
    }

    // check for drama genre
    DramaMovie* drama = dynamic_cast<DramaMovie*>(movie);
    if(drama != nullptr) {
        // check if movie is already in inventory
        set<shared_ptr<DVD>, comp>::iterator it;
        it = dramas.find(dvd_ptr);

        // if movie must be added to inventory
        if(it == dramas.end()) {
            dvd_ptr->addStock(amount);       // assuming the precondition
            dramas.insert(dvd_ptr);
        }

        // otherwise adjust stock for existing inventory
        else {
            it->get()->addStock(amount);
//            DVD & disk = static_cast<DVD &>(*it->get());
//            disk.addStock(amount);
        }
    }

    // check for classics genre
    ClassicMovie* classic = dynamic_cast<ClassicMovie*>(movie);
    if(classic != nullptr) {
        // check if movie is already in inventory
        set<shared_ptr<DVD>, comp>::iterator it;
        it = classics.find(dvd_ptr);

        // if the movie is already in inventory
        if(it != classics.end()) {
            // look for equivalent classics (i.e. same title, different actor)
            set<shared_ptr<DVD>, comp>::iterator equivIt;
            for(equivIt = classics.begin(); equivIt != classics.end(); ++equivIt) {
                // add stock for all listings of movie
                if(it->get()->getTitle() == equivIt->get()->getTitle())
                    equivIt->get()->addStock(amount);
            }
        }

        // otherwise this movie listing must be added to inventory
        else {
            // first check for alternate listings of the movie
            bool hasAlts = false;

            for(it = classics.begin(); it != classics.end(); ++it) {
                // if alternate listing is found, adjust for existing stock & set flag
                if(dvd_ptr->getTitle() == it->get()->getTitle()) {
                    dvd_ptr->setTotalStock(it->get()->getTotalStock());
                    dvd_ptr->setAvailableStock(it->get()->getAvailableStock());
                    hasAlts = true;
                    break;
                }
            }

            // if there are multiple listings, add new stock to all listings
            if(hasAlts) {
                classics.insert(dvd_ptr);

                for(it = classics.begin(); it != classics.end(); ++it) {
                    if(dvd_ptr->getTitle() == it->get()->getTitle())
                        it->get()->addStock(amount);
                }
            }

            // otherwise only add lone listing of movie
            else {
                dvd_ptr->addStock(amount);
                classics.insert(dvd_ptr);
            }
        }
    }
}

/**-------------------------------- borrow ------------------------------------
 * tries to borrow an item from the inventory for a customer
 * @param item the item to be borrowed
 * @throws if item is not found in inventory
 * @throws if item is out of stock
 */
void Inventory::borrow(DVD & dvd) {
    // first convert the DVD reference to shared_ptr
    shared_ptr<DVD> dvd_ptr = make_shared<DVD>(dvd);

    // check which genre of movie is on DVD
    Movie* movie = &dvd_ptr->getMovie();    // pointer fails to nullptr for following dynamic_cast checks
                                            // whereas a reference fails with an exception, so use pointer
    // check for comedy genre
    ComedyMovie* comedy = dynamic_cast<ComedyMovie*>(movie);
    if(comedy != nullptr) {
        // check if movie is in inventory
        set<shared_ptr<DVD>, comp>::iterator it;
        it = comedies.find(dvd_ptr);

        // if movie is not in inventory
        if(it == comedies.end())
            throw runtime_error("movie is not in inventory");

        // if movie is out of stock
        if(it->get()->getAvailableStock() == 0)
            throw runtime_error("movie is out of stock");

        // otherwise safely borrow
        it->get()->borrow();
        return;
    }

    // check for drama genre
    ComedyMovie* drama = dynamic_cast<ComedyMovie*>(movie);
    if(drama != nullptr) {
        // check if movie is already in inventory
        set<shared_ptr<DVD>, comp>::iterator it;
        it = dramas.find(dvd_ptr);

        // if movie is not in inventory
        if(it == dramas.end())
            throw runtime_error("movie is not in inventory");

        // if movie is out of stock
        if(it->get()->getAvailableStock() == 0)
            throw runtime_error("movie is out of stock");

        // otherwise safely borrow
        it->get()->borrow();
        return;
    }

    // check for classics genre
    ComedyMovie* classic = dynamic_cast<ComedyMovie*>(movie);
    if(classic != nullptr) {
        // check if movie is already in inventory
        set<shared_ptr<DVD>, comp>::iterator it;
        it = classics.find(dvd_ptr);

        // if movie is not in inventory
        if(it == classics.end())
            throw runtime_error("movie is not in inventory");

        // if movie is out of stock
        if(it->get()->getAvailableStock() == 0)
            throw runtime_error("movie is out of stock");

        // otherwise safely borrow for all listings of movie (i.e. same title, different actor)
        set<shared_ptr<DVD>, comp>::iterator equivIt;
        for(equivIt = classics.begin(); equivIt != classics.end(); ++equivIt) {
            if(it->get()->getTitle() == equivIt->get()->getTitle())
                equivIt->get()->borrow();
        }

        return;
    }
}

/**-------------------------------- restock -----------------------------------
 * restocks an item in the inventory when returned by a customer
 * @param item the item to be restocked
 * @throws if item is not stocked by inventory
 * @throws if inventory is already full
 */
void Inventory::restock(DVD & dvd) {
    // first convert the DVD reference to shared_ptr
    shared_ptr<DVD> dvd_ptr = make_shared<DVD>(dvd);

    // check which genre of movie is on DVD
    Movie* movie = &dvd_ptr->getMovie();    // pointer fails to nullptr for following dynamic_cast checks
                                            // whereas a reference fails with an exception, so use pointer
    // check for comedy genre
    ComedyMovie* comedy = dynamic_cast<ComedyMovie*>(movie);
    if(comedy != nullptr) {
        // check if movie is stocked in inventory
        set<shared_ptr<DVD>, comp>::iterator it;
        it = comedies.find(dvd_ptr);

        // if movie is not stocked in inventory
        if(it == comedies.end())
            throw runtime_error("movie is not stocked by inventory");

        // if movie stock is full
        if(it->get()->getAvailableStock() == it->get()->getTotalStock())
            throw runtime_error("inventory for this movie is full");

        // otherwise safely restock
        it->get()->restock();
        return;
    }

    // check for drama genre
    ComedyMovie* drama = dynamic_cast<ComedyMovie*>(movie);
    if(drama != nullptr) {
        // check if movie is stocked in inventory
        set<shared_ptr<DVD>, comp>::iterator it;
        it = dramas.find(dvd_ptr);

        // if movie is not stocked in inventory
        if(it == dramas.end())
            throw runtime_error("movie is not stocked by inventory");

        // if movie stock is full
        if(it->get()->getAvailableStock() == it->get()->getTotalStock())
            throw runtime_error("inventory for this movie is full");

        // otherwise safely restock
        it->get()->restock();
        return;
    }

    // check for classics genre
    ComedyMovie* classic = dynamic_cast<ComedyMovie*>(movie);
    if(classic != nullptr) {
        // check if movie is stocked in inventory
        set<shared_ptr<DVD>, comp>::iterator it;
        it = classics.find(dvd_ptr);

        // if movie is not stocked in inventory
        if(it == classics.end())
            throw runtime_error("movie is not stocked by inventory");

        // if movie stock is full
        if(it->get()->getAvailableStock() == it->get()->getTotalStock())
            throw runtime_error("inventory for this movie is full");

        // otherwise safely restock for all listings of movie (i.e. same title, different actor)
        set<shared_ptr<DVD>, comp>::iterator equivIt;
        for(equivIt = classics.begin(); equivIt != classics.end(); ++equivIt) {
            if(it->get()->getTitle() == equivIt->get()->getTitle())
                equivIt->get()->restock();
        }

        return;
    }
}
