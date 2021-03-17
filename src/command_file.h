/**
 * @file command_file.h
 * @author Dominic Ewing
 */

#ifndef COMMAND_FILE_H
#define COMMAND_FILE_H

#include <memory>   // shared_ptr, unique_ptr
#include <regex>    // regex, regex_search, smatch
#include <stdexcept>    // runtime_error
#include <string>   // string
#include <vector>   // vector

#include "command.h"
#include "dvd.h"

/**
 * Represents an command file. The file can be parsed to create a list of
 * command objects.
 */
class CommandFile
{
public:
    // Constructor
    explicit CommandFile(std::string filePath);

    // Retrieve commands and errors
    std::vector<std::shared_ptr<Command>> commands();
    std::vector<std::shared_ptr<std::runtime_error>> errors();

private:
    std::string file_path;  // Path to the command file

    // Cache from previously parsing the file. This prevents re-parsing
    // for each separate call to commands() and errors().
    bool parsed{false};
    std::vector<std::shared_ptr<Command>> file_commands{};
    std::vector<std::shared_ptr<std::runtime_error>> file_errors{};

    // Helper methods for performing file parsing and updating cache.
    void parseFile();
    DVD parseDVD(const std::string& line);
    void logError(const std::string& line);

    // Since the requirements dictate that the formatting of the file is
    // correct, these can be easily parsed with regualar expressions. These
    // regular expressions are purposefully very permissive in accepting names
    // for directors, actors, and titles. It seems better to allow some odd
    // inputs than to be unable to add movies from "Daniel Day-Lewis",
    // "Lupita Nyong'o" or "50 Cent" because their names (or screen names) are
    // not supported by the program. The main technical limitiations stem from
    // the use of spaces and commas as field separators.
    const std::regex inventory_pattern {
        "I[[:space:]]+$"        // The action type I and no other fields
    };

    const std::regex history_pattern {
        "H "                    // The action type H
        "([[:digit:]]{4})"      // The 4-digit customer id
    };

    const std::regex borrow_pattern {
        "B "                    // The action type B
        "([[:digit:]]{4})"      // The 4-digit customer id
    };

    const std::regex return_pattern {
        "R "                    // The action type R
        "([[:digit:]]{4})"      // The 4-digit customer id
    };

    // At this point all items are DVDs. So, movie types are simply parsed
    // as DVDs. If this system changes to accept move media types, this
    // will need to be updated.
    const std::regex comedy_pattern {
        "D F "                  // DVD & Movie type F
        "([^,]+), "             // Title
        "([[:digit:]]+)"        // Release Year
    };

    const std::regex drama_pattern {
        "D D "                  // DVD & Movie type D
        "([^,]+), "             // Director
        "([^,\r]+)"             // Title
    };

    const std::regex classic_pattern {
        "D C "                  // DVD & Movie type C
        "([[:digit:]]{1,2}) "   // Release month
        "([[:digit:]]+) "       // Release year
        "([^,\r]+)"             // Actor
    };
};

#endif
