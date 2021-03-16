/**
 * @file command_file.cpp
 * @author Dominic Ewing
 */

#include <fstream>  // ifstream

#include "borrow_command.h"
#include "classic_movie.h"
#include "comedy_movie.h"
#include "command_file.h"
#include "drama_movie.h"
#include "history_command.h"
#include "inventory_command.h"
#include "restock_command.h"

/**
 * Constructor - Construct a command file object.
 *
 * @param filePath Path to the command file.
 */
CommandFile::CommandFile(std::string filePath)
    : file_path{std::move(filePath)}
{
}

/**
 * commands - Read the command file to produce a list of commands based on its
 *            contents.
 *
 * @return A list of command objects read from the file.
 */
std::vector<std::shared_ptr<Command>> CommandFile::commands()
{
    // Parse the file if there is no data in cache.
    if (!parsed)
    {
        parseFile();
    }

    return file_commands;
}

/**
 * errors - Provide all the errors encountered while parsing the file.
 *
 * @return A list of all parsing errors.
 */
std::vector<std::shared_ptr<std::runtime_error>> CommandFile::errors()
{
    // Parse the file if there is no data in cache.
    if (!parsed)
    {
        parseFile();
    }

    return file_errors;
}

/**
 * parseFile - Parse the file and store its contents in the cache.
 */
void CommandFile::parseFile()
{
    std::ifstream stream{file_path};

    for (std::string line; std::getline(stream, line); )
    {
        std::smatch inventory_match;
        std::smatch history_match;
        std::smatch borrow_match;
        std::smatch return_match;

        // Match based on command type: inventory, history, borrow, or
        // return
        if (std::regex_search(line, inventory_match, inventory_pattern))
        {
            file_commands.emplace_back(
                std::shared_ptr<Command>{
                    new InventoryCommand{}
            });
        }
        else if (std::regex_search(line, history_match, history_pattern))
        {
            file_commands.emplace_back(
                std::shared_ptr<Command>{new HistoryCommand{
                    stoi(history_match[1])
            }});
        }
        else if (std::regex_search(line, borrow_match, borrow_pattern))
        {
            try
            {
                // Throws an error if there is no matching dvd
                auto item = parseDVD(line);
                file_commands.emplace_back(
                    std::shared_ptr<Command>{new BorrowCommand{
                        stoi(borrow_match[1]),
                        std::make_unique<DVD>(item)
                }});
            }
            catch (const std::runtime_error& error)
            {
                logError(line);
            }
        }
        else if (std::regex_search(line, return_match, return_pattern))
        {
            try
            {
                // Throws an error if there is no matching dvd
                auto item = parseDVD(line);
                file_commands.emplace_back(
                    std::shared_ptr<Command>{new RestockCommand{
                        stoi(return_match[1]),
                        std::make_unique<DVD>(item)
                }});
            }
            catch (const std::runtime_error& error)
            {
                logError(line);
            }
        }
        else
        {
            logError(line);
        }
    }

    // Indicate there is a valid cache
    parsed = true;
}

/**
 * parseDVD - Parse a line in the file to build the involved DVD object.
 *
 * This method fills in as much information as possible, but the command file
 * does not contain all the movie information. Any missing fields are simply
 * left as the empty string, or the value -1 to indicate missing data.
 *
 * @param line The line in the command file.
 * @return The matching DVD object.
 * @throws std::runtime_error if there is no matching DVD movie format
 */
DVD CommandFile::parseDVD(const std::string& line)
{
    std::smatch comedy_match;
    std::smatch drama_match;
    std::smatch classic_match;

    // Match based on movie type: comedy, drama, or classic
    if (std::regex_search(line, comedy_match, comedy_pattern))
    {
        return DVD{std::shared_ptr<Movie>{new ComedyMovie(
            "comedy",               // .genre
            "",                     // .director
            comedy_match[1],        // .title
            stoi(comedy_match[2])   // .releaseYear
        )}};
    }
    else if (std::regex_search(line, drama_match, drama_pattern))
    {
        return DVD{std::shared_ptr<Movie>{new DramaMovie(
            "drama",                // .genre
            drama_match[1],         // .director
            drama_match[2],         // .title
            -1                      // .releaseYear
        )}};
    }
    else if (std::regex_search(line, classic_match, classic_pattern))
    {
        return DVD{std::shared_ptr<Movie>{new ClassicMovie(
            "classic",              // .genre
            "",                     // .director
            "",                     // .title
            stoi(classic_match[2]), // .releaseYear
            stoi(classic_match[1]), // .releaseMonth
            classic_match[3]        // .actor
        )}};
    }
    else
    {
        throw std::runtime_error("No matching DVD format");
    }
}

/**
 * logError - Add an error message to the list of parsing errors.
 *
 * @param line The input line where the error occurs.
 */
void CommandFile::logError(const std::string& line)
{
    file_errors.emplace_back(
        std::make_shared<std::runtime_error>(
            "[Invalid command] " + line
    ));
}
