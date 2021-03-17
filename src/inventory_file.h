/**
 * @file inventory_file.h
 * @author Dominic Ewing
 */

#ifndef INVENTORY_FILE_H
#define INVENTORY_FILE_H

#include <regex>    // regex, regex_search, smatch
#include <string>   // string
#include <vector>   // vector

#include "inventory.h"

/**
 * Represents an inventory file. The file can be parsed to create an inventory
 * object in memory.
 */
class InventoryFile
{
public:
    // Constructor
    explicit InventoryFile(std::string filePath);

    // Retrieve inventory and errors
    Inventory inventory();
    std::vector<std::shared_ptr<std::runtime_error>> errors();

private:
    std::string file_path;      // Path to the inventory file

    // Cache from previously parsing the file. This prevents re-parsing
    // for each separate call to inventory() and errors().
    bool parsed{false};
    Inventory file_inventory{};
    std::vector<std::shared_ptr<std::runtime_error>> error_list{};

    // Helper method for perfoming file parsing and updating cache.
    void parseFile();

    // Since the requirements dictate that the formatting of the file is
    // correct, these can be easily parsed with regualar expressions. These
    // regular expressions are purposefully very permissive in accepting names
    // for directors, actors, and titles. It seems better to allow some odd
    // inputs than to be unable to add movies from "Daniel Day-Lewis",
    // "Lupita Nyong'o" or "50 Cent" because their names (or screen names) are
    // not supported by the program. The main technical limitiations stem from
    // the use of spaces and commas as field separators.
    const std::regex comedy_pattern {
        "F, "                   // F for comdedy
        "([[:digit:]]+), "      // stock
        "([^,]+), "             // director
        "([^,]+), "             // title
        "([[:digit:]]+)"        // year
    };

    const std::regex drama_pattern {
        "D, "                   // D for drama
        "([[:digit:]]+), "      // stock
        "([^,]+), "             // director
        "([^,]+), "             // title
        "([[:digit:]]+)"        // year
    };

    const std::regex classic_pattern {
        "C, "                   // C for classic movie
        "([[:digit:]]+), "      // stock
        "([^,]+), "             // director
        "([^,]+), "             // title
        "([^, ]+ [^, ]+) "      // major actor
        "([[:digit:]]{1,2}) "   // release month
        "([[:digit:]]+)"        // release year
    };
};

#endif
