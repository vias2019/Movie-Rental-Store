/**
 * @file inventory_file.cpp
 * @author Dominic Ewing
 */

#include <fstream>      // ifstream

#include "inventory_file.h"

/**
 * Constructor - Construct an inventory file object.
 *
 * @param filePath Path to the inventory file.
 */
InventoryFile::InventoryFile(std::string filePath)
    : file_path{std::move(filePath)}
{
}

/**
 * inventory - Create an inventory object representing the contents of the file.
 *
 * @return An inventory object representing the contents of the file.
 */
Inventory InventoryFile::inventory()
{
    // Parse the file if there is no data in cache
    if (!parsed)
    {
        parseFile();
    }

    return file_inventory;
}

/**
 * errors - Provide all the errors encountered while parsing the file.
 *
 * @return A list of all parsing errors.
 */
std::vector<std::shared_ptr<std::runtime_error>> InventoryFile::errors()
{
    // Parse the file if there is no data in cache
    if (!parsed)
    {
        parseFile();
    }

    return error_list;
}

/**
 * parseFile - Perform file parsing and cache the inventory and list of parsing
 *             errors.
 */
void InventoryFile::parseFile()
{
    std::ifstream stream{file_path};

    for (std::string line; std::getline(stream, line); )
    {
        std::smatch comedy_match;
        std::smatch drama_match;
        std::smatch classic_match;

        // Match based on movie type
        if (std::regex_search(line, comedy_match, comedy_pattern))
        {
            file_inventory.addStock(
                DVD(std::shared_ptr<Movie>{new ComedyMovie(
                    "comedy",               // .genre
                    comedy_match[2],        // .director
                    comedy_match[3],        // .title
                    stoi(comedy_match[4])   // .releaseYear
                )}),
                stoi(comedy_match[1])       // .quantity
            );
        }
        else if (std::regex_search(line, drama_match, drama_pattern))
        {
            file_inventory.addStock(
                DVD(std::shared_ptr<Movie>{new DramaMovie(
                    "drama",                // .genre
                    drama_match[2],         // .director
                    drama_match[3],         // .title
                    stoi(drama_match[4])    // .releaseYear
                )}),
                stoi(drama_match[1])        // .quantity
            );
        }
        else if (std::regex_search(line, classic_match, classic_pattern))
        {
            file_inventory.addStock(
                DVD(std::shared_ptr<Movie>{new ClassicMovie(
                    "classic",              // .genre
                    classic_match[2],       // .director
                    classic_match[3],       // .title
                    stoi(classic_match[6]), // .releaseYear
                    stoi(classic_match[5]), // .releaseMonth
                    classic_match[4]        // .actor
                )}),
                stoi(classic_match[1])      // .quantity
            );
        }
        else
        {
            error_list.emplace_back(
                std::make_shared<std::runtime_error>(
                    "[Invalid inventory item] " + line
            ));
        }
    }

    // Mark the cache as valid
    parsed = true;
}
