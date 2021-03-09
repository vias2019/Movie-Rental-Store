/**
 * @file dvd.h
 * @author Austin Arlitt
 */

#ifndef DVD_H
#define DVD_H

#include "item.h"
#include "movie.h"
using namespace std;

/**
 * A class for DVD media stocked in the rental store inventory
 */
class DVD : public Item {
    friend ostream& operator<<(ostream &, const DVD &);     // displays DVD movie & stock

public:
    DVD(Movie &, int = 0, int = 0);   // constructor
    ~DVD();                         // destructor
    void addStock(int) override;    // adds total stock to inventory
    void borrow() override;         // attempts to check out DVD for a customer, decreasing stock
    void restock() override;        // returns a borrowed DVD, increasing stock

    // comparison operator
    int compare(const DVD &);

private:
    int totalStock;                 // total stock of DVD in inventory
    int availableStock;             // currently available stock of DVD
    shared_ptr<Movie> movie;        // the movie on the DVD
};

#endif
