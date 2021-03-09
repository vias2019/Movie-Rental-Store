/**
 * @file comedy_movie.h
 * @author Austin Arlitt
 */

#ifndef COMEDY_MOVIE_H
#define COMEDY_MOVIE_H

// includes TBD
using namespace std;

/**
 * A class for comedy movies in the rental movie store
 */
class ComedyMovie : public Movie {
    friend ostream& operator<<(ostream &, const ComedyMovie &);     // displays movie

public:
    ComedyMovie(string, string, string, int);       // constructor
    int compare(const Movie &) const override;      // compares two movies

private:
    string genre;
    string director;
    string title;
    int releaseYear;
};

#endif