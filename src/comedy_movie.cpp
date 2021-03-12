/**
 * @file comedy_movie.cpp
 * @author Austin Arlitt
 */

#include "comedy_movie.h"
#include <sstream>


/**-------------------------------- operator<< --------------------------------
 * displays the movie's director, title, and release year
 * @param out the ostream
 * @param movie the movie
 * @return the ostream
 */
ostream& operator<<(ostream & out, const ComedyMovie & movie) {
    out << movie.director << ", " << movie.title << ", " << movie.releaseYear;

    return out;
}

/**-------------------------------- constructor -------------------------------
 * @param genre the movie's genre
 * @param director the movie's director
 * @param title the movie's title
 * @param releaseYear the movie's releaseYear
 */
ComedyMovie::ComedyMovie(string genre, string director, string title, int releaseYear) {
    this->genre = genre;
    this->director = director;
    this->title = title;
    this->releaseYear = releaseYear;
}

/**------------------------------- destructor ---------------------------------
 * deallocates memory
 */
ComedyMovie::~ComedyMovie() = default;

/**--------------------------------- compare ----------------------------------
 * compares two movies (comedies are sorted by title, then release year)
 * @return -1/0/1 if this movie is less than/equal to/greater than the rhs
 */
int ComedyMovie::compare(const Movie & rhs) const {
    // early exit case
    if(this == &rhs)
        return 0;

    // first compare genres (comedy < drama < classics)
    if(rhs.getGenre() != "F")
        return -1;

    // otherwise compare comedies by title
    if(title < rhs.getTitle())
        return -1;
    if(title > rhs.getTitle())
        return 1;

    // then compare release years
    if(releaseYear < rhs.getReleaseYear())
        return -1;
    if(releaseYear > rhs.getReleaseYear())
        return 1;

    // movies must be equal
    return 0;
}

/**--------------------------------- getGenre ---------------------------------
 * @return the movie's genre
 */
string ComedyMovie::getGenre() const {
    return genre;
}

/**-------------------------------- getDirector -------------------------------
 * @return the movie's director
 */
string ComedyMovie::getDirector() const {
    return director;
}

/**--------------------------------- getTitle ---------------------------------
 * @return the movie's title
 */
string ComedyMovie::getTitle() const {
    return title;
}

/**------------------------------- getReleaseYear -----------------------------
 * @return the movie's release year
 */
int ComedyMovie::getReleaseYear() const {
    return releaseYear;
}

/**-------------------------------- toString-----------------------------------
 * represent the movie as a string
 * e.g. Robert Zemeckis, Back to the Future, 1985
 */
std::string ComedyMovie::toString() const
{
    std::stringstream stream;
    stream << *this;
    return stream.str();
}
