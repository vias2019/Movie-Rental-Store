/**
 * @file classic_movie.h
 * @author Austin Arlitt
 */

#ifndef CLASSIC_MOVIE_H
#define CLASSIC_MOVIE_H

// includes TBD
using namespace std;

/**
 * A class for classic movies in the rental movie store
 */
class ClassicMovie : public Movie {
public:
    ClassicMovie(string, string, string, int, int, string);     // constructor
    int compare(const Movie &);                         // compares two movies

private:
    string genre;
    string director;
    string title;
    int releaseYear;
    int releaseMonth;
    string actor;
};

#endif