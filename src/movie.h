/**
 * @file movie.h
 * @author Austin Arlitt
 */

#ifndef MOVIE_H
#define MOVIE_H


/**
 * Abstract base class for movies
 */
class Movie {
public:
    virtual int compare(const Movie &) const = 0;       // compares two movies
    virtual std::string getGenre() const = 0;
    virtual std::string getDirector() const = 0;
    virtual std::string getTitle() const = 0;
    virtual int getReleaseYear() const = 0;
};

#endif
