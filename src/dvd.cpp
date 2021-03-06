/**
 * @file dvd.cpp
 * @author Austin Arlitt
 */

#include <sstream>
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
        << ' ' << disk.getMovie().toString();

    return out;
}

/**-------------------------- default constructor -----------------------------
 * creates an empty DVD with null movie ptr & 0 stock
 */
DVD::DVD() {
    movie = nullptr;
    totalStock = 0;
    availableStock = 0;
}

/**------------------------------ constructor ---------------------------------
 * creates a DVD from a movie and the total/available stock (both default to 0)
 * @param film the movie on the DVD
 * @param total the total stock of the DVD
 * @param available the available stock of the DVD
 */
DVD::DVD(std::shared_ptr<Movie> film, int total, int available)
	: totalStock{total}, availableStock{available}, movie{film}
{
}

/**------------------------------- destructor ---------------------------------
 * deallocates memory
 */
DVD::~DVD() = default;

/**------------------------------- addStock -----------------------------------
 * adds stock of the DVD to inventory
 * @param stock the amount of stock to add to inventory
 */
void DVD::addStock(int stock) {
    totalStock += stock;
    availableStock += stock;
}

/**-------------------------------- borrow ------------------------------------
 * borrows a copy of the DVD, decreasing available stock by one
 */
void DVD::borrow() {
    if(availableStock > 0)
        --availableStock;
}

/**-------------------------------- restock -----------------------------------
 * restocks a copy of the DVD, increasing available stock by one
 */
void DVD::restock() {
    if(availableStock < totalStock)
        ++availableStock;
}

/**-------------------------------- toString-----------------------------------
 * represent the DVD as a string
 * displays the available/total stock & movie for the DVD
 * e.g. [7/10] Robert Zemeckis, Back to the Future, 1985
 */
std::string DVD::toString() const
{
	std::stringstream stream;
	stream << *this;
	return stream.str();
}

/**-------------------------------- getMovie ----------------------------------
 * retrieves the movie on the DVD
 * @return the movie on the DVD
 */
Movie& DVD::getMovie() const {
//    Movie& film = static_cast<Movie &>(*movie);

    return *movie;
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

/**------------------------------- resetStock ---------------------------------
 * resets total/available stock to zero
 */
void DVD::resetStock() {
    totalStock = 0;
    availableStock = 0;
}

/**------------------------------ setTotalStock -------------------------------
 * sets the total stock of the DVD
 * @param total the new total stock
 */
void DVD::setTotalStock(int total) {
    totalStock = total;
}

/**---------------------------- setAvailableStock -----------------------------
 * sets the available stock of the DVD
 * @param available the new available stock
 */
void DVD::setAvailableStock(int available) {
    availableStock = available;
}
