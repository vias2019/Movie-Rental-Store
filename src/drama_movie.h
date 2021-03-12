/**
 * @file drama_movie.h
 * @author Austin Arlitt
 */

#ifndef DRAMA_MOVIE_H
#define DRAMA_MOVIE_H

#include <iostream>
#include "movie.h"
using namespace std;

/**
 * A class for drama movies in the rental movie store
 */
class DramaMovie : public Movie {
    friend ostream& operator<<(ostream &, const DramaMovie &);          // displays movie

public:
    DramaMovie(string genre, string director, string title, int releaseYear);   // constructor
    ~DramaMovie() override;                                                     // destructor
    int compare(const Movie &) const override;                          // compares two movies

    // accessors
    string getGenre() const override;
    string getDirector() const override;
    string getTitle() const override;
    int getReleaseYear() const override;
    string toString() const override;

private:
    string genre;
    string director;
    string title;
    int releaseYear;
};

#endif