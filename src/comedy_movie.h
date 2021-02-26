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
public:
    ComedyMovie(string, string, string, int);       // constructor
    int compare(const Movie &);                     // compares two movies

private:
    string genre;
    string director;
    string title;
    int releaseYear;
};

#endif
