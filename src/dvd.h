/**
 * @file dvd.h
 * @author Austin Arlitt
 */

#ifndef DVD_H
#define DVD_H

#include <memory>
#include <iostream>
#include "item.h"
#include "movie.h"
using namespace std;

/**
 * A class for DVD media stocked in the rental store inventory
 */
class DVD : public Item {
    friend ostream& operator<<(ostream &, const DVD &);     // displays DVD movie & stock

public:
    DVD();                              // default constructor
    DVD(std::shared_ptr<Movie>, int = 0, int = 0);     // constructor
    ~DVD() override;                    // destructor
    void addStock(int) override;        // adds total stock to inventory
    void borrow() override;             // attempts to check out DVD for a customer, decreasing stock
    void restock() override;            // returns a borrowed DVD, increasing stock
    std::string toString() const override;	// represent the DVD as a string

    // accessors
    Movie& getMovie() const;            // get the movie on the DVD
    string getTitle() const;            // get the title of the movie on the DVD
    int getTotalStock() const;          // get total stock of DVD
    int getAvailableStock() const;      // get available stock of DVD

    int compare(const DVD &) const;     // comparison operator

    // utility functions (intended for use by Inventory only)
    void resetStock();                  // resets stock to zero
    void setTotalStock(int);            // set total stock of DVD
    void setAvailableStock(int);        // set available stock of DVD

private:
    int totalStock;                 // total stock of DVD in inventory
    int availableStock;             // currently available stock of DVD
    shared_ptr<Movie> movie;        // the movie on the DVD
};

#endif
