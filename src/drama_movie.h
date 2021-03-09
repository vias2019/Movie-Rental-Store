/**
 * @file drama_movie.h
 * @author Austin Arlitt
 */

#ifndef DRAMA_MOVIE_H
#define DRAMA_MOVIE_H

// includes TBD
using namespace std;

/**
 * A class for drama movies in the rental movie store
 */
class DramaMovie : public Movie {
    friend ostream& operator<<(ostream &, const DramaMovie &);  // displays movie

public:
    DramaMovie(string, string, string, int);        // constructor
    int compare(const Movie &) const override;      // compares two movies

private:
    string genre;
    string director;
    string title;
    int releaseYear;
};

#endif