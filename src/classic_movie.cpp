/**
 * @file classic_movie.cpp
 * @author Austin Arlitt
 */

#include "classic_movie.h"


/**-------------------------------- operator<< --------------------------------
 * displays the movie's director, title, actor, and release date
 * @param out the ostream
 * @param movie the movie
 * @return the ostream
 */
ostream& operator<<(ostream & out, const ClassicMovie & movie) {
    out << movie.director << ", " << movie.title << ", " << movie.actor << ", "
        << movie.releaseMonth << ' ' << movie.releaseYear;

    return out;
}

/**-------------------------------- constructor -------------------------------
 * @param genre the movie's genre
 * @param director the movie's director
 * @param title the movie's title
 * @param releaseYear the movie's releaseYear
 */
ClassicMovie::ClassicMovie(string genre, string director, string title,
                           int releaseYear, int releaseMonth, string actor) {
    this->genre = genre;
    this->director = director;
    this->title = title;
    this->releaseYear = releaseYear;
    this->releaseMonth = releaseMonth;
    this->actor = actor;
}

/**------------------------------- destructor ---------------------------------
 * deallocates memory
 */
ClassicMovie::~ClassicMovie() = default;

/**--------------------------------- compare ----------------------------------
 * compares two movies (classics are sorted by release date, then major actor)
 * @return -1, 0, 1 if this movie is less than/equal to/greater than the rhs
 */
int ClassicMovie::compare(const Movie & rhs) const {
    // early exit case
    if(this == &rhs)
        return 0;

    // first compare genres (comedy < drama < classics)
    if(rhs.getGenre() != "C")
        return 1;

    // otherwise compare release year
    if(releaseYear < rhs.getReleaseYear())
        return -1;
    if(releaseYear > rhs.getReleaseYear())
        return 1;

    // downcast to access child class data
    const ClassicMovie & mov = dynamic_cast<const ClassicMovie &>(rhs);

    // then compare release month
    if(releaseMonth < mov.releaseMonth)
        return -1;
    if(releaseMonth > mov.releaseMonth)
        return 1;

    // then compare actor
    if(actor < mov.actor)
        return -1;
    if(actor > mov.actor)
        return 1;

    // movies must be equal
    return 0;
}

/**--------------------------------- getGenre ---------------------------------
 * @return the movie's genre
 */
string ClassicMovie::getGenre() const {
    return genre;
}

/**-------------------------------- getDirector -------------------------------
 * @return the movie's director
 */
string ClassicMovie::getDirector() const {
    return director;
}

/**--------------------------------- getTitle ---------------------------------
 * @return the movie's title
 */
string ClassicMovie::getTitle() const {
    return title;
}

/**------------------------------- getReleaseYear -----------------------------
 * @return the movie's release year
 */
int ClassicMovie::getReleaseYear() const {
    return releaseYear;
}

/**----------------------------- getReleaseMonth ------------------------------
 * @return the movie's release month
 */
int ClassicMovie::getReleaseMonth() const {
    return releaseMonth;
}

/**-------------------------------- getActor ----------------------------------
 * @return the movie's actor
 */
string ClassicMovie::getActor() const {
    return actor;
}
