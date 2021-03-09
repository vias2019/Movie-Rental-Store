/**
 * @file movie.h
 * @author Austin Arlitt
 */

#ifndef MOVIE_H
#define MOVIE_H

// includes TBD

/**
 * Abstract base class for movies
 */
class Movie {
    virtual int compare(const Movie &) const = 0;       // compares two movies
};

#endif
