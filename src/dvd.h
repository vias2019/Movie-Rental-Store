/**
 * @file dvd.h
 * @author Austin Arlitt
 */

#ifndef DVD_H
#define DVD_H

// includes TBD

/**
 * A class for DVD media stocked in the rental store inventory
 */
class DVD : public Item {
public:
    DVD(Movie, int = 0, int = 0);   // constructor
    void addStock(int);             // adds total stock to inventory
    void borrow();                  // attempts to check out DVD for a customer, decreasing stock
    void restock();                 // returns a borrowed DVD, increasing stock

    // comparison operator
    int compare(const DVD &);

private:
    int totalStock;         // total stock of DVD in inventory
    int availableStock;     // currently available stock of DVD
    Movie movie;            // the movie on the DVD
};

#endif
