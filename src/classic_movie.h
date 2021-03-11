/**
 * @file classic_movie.h
 * @author Austin Arlitt
 */

#ifndef CLASSIC_MOVIE_H
#define CLASSIC_MOVIE_H

#include <iostream>
#include "movie.h"
using namespace std;

/**
 * A class for classic movies in the rental movie store
 */
class ClassicMovie : public Movie {
    friend ostream& operator<<(ostream &, const ClassicMovie &);        // displays movie

public:
    ClassicMovie(string genre, string director, string title,
                 int releaseYear, int releaseMonth, string actor);      // constructor
    int compare(const Movie &) const override;                          // compares two movies

    // accessors
    string getGenre() const override;
    string getDirector() const override;
    string getTitle() const override;
    int getReleaseYear() const override;
    int getReleaseMonth() const;
    string getActor() const;

private:
    string genre;
    string director;
    string title;
    int releaseYear;
    int releaseMonth;
    string actor;
};

#endif