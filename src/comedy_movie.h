/**
 * @file comedy_movie.h
 * @author Austin Arlitt
 */

#ifndef COMEDY_MOVIE_H
#define COMEDY_MOVIE_H

#include <iostream>
#include "movie.h"
using namespace std;

/**
 * A class for comedy movies in the rental movie store
 */
class ComedyMovie : public Movie {
    friend ostream& operator<<(ostream &, const ComedyMovie &);         // displays movie

public:
    ComedyMovie(string genre, string director, string title, int releaseYear);  // constructor
    ~ComedyMovie() override;                                                    // destructor
    int compare(const Movie &) const override;                          // compares two movies

    // accessors
    string getGenre() const override;
    string getDirector() const override;
    string getTitle() const override;
    int getReleaseYear() const override;

private:
    string genre;
    string director;
    string title;
    int releaseYear;
};

#endif
