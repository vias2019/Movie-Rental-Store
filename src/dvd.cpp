/**
 * @file dvd.cpp
 * @author Austin Arlitt
 */

#include "dvd.h"


/**------------------------------- operator<< ---------------------------------
 * displays the available/total stock & movie for the DVD
 * e.g. [7/10] Robert Zemeckis, Back to the Future, 1985
 * @param out the ostream
 * @param disk the DVD
 * @return the ostream
 */
ostream& operator<<(ostream & out, const DVD & disk) {
    out << '[' << disk.availableStock << " of " << disk.totalStock << ']'
        << ' ' << disk.getMovie();

    return out;
}

/**------------------------------ constructor ---------------------------------
 * creates a DVD from a movie and the total/available stock (both default to 0)
 * @param film the movie on the DVD
 * @param total the total stock of the DVD
 * @param available the available stock of the DVD
 */
DVD::DVD(Movie & film, int total, int available) {
    movie = static_cast<shared_ptr<Movie>>(&film);
    totalStock = total;
    availableStock = available;
}

/**------------------------------- addStock -----------------------------------
 * adds stock of the DVD to inventory
 * @param stock the amount of stock to add to inventory
 */
void DVD::addStock(int stock) {
    totalStock += stock;
    availableStock += stock;
}




/**-------------------------------- getMovie ----------------------------------
 * retrieves the movie on the DVD
 * @return the movie on the DVD
 */
Movie& DVD::getMovie() const {
    Movie& film = static_cast<Movie &>(*movie);

    return film;
}

/**-------------------------------- getTitle ----------------------------------
 * retrieves the title of the movie on the DVD
 * @return the title of the movie on the DVD
 */
string DVD::getTitle() const {
    Movie& film = getMovie();

    return film.getTitle();
}

/**------------------------------ getTotalStock -------------------------------
 * retrieves the total stock of the DVD in inventory
 * @return the total stock of the DVD in inventory
 */
int DVD::getTotalStock() const {
    return totalStock;
}

/**---------------------------- getAvailableStock -----------------------------
 * retrieves the available stock of the DVD in inventory
 * @return the available stock of the DVD in inventory
 */
int DVD::getAvailableStock() const {
    return availableStock;
}

/**-------------------------------- compare -----------------------------------
 * compares the movies on two DVDs
 * @param rhs the DVD to compare to
 * @return -1/0/1 if this DVD's movie is less than/equal to/greater than rhs's
 */
int DVD::compare(const DVD & rhs) const {
    return getMovie().compare(rhs.getMovie());
}

