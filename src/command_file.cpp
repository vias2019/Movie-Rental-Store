/**
 * @file command_file.cpp
 * @author Dominic Ewing
 */

#include <fstream>

#include "borrow_command.h"
#include "classic_movie.h"
#include "comedy_movie.h"
#include "command_file.h"
#include "drama_movie.h"
#include "history_command.h"
#include "inventory_command.h"
#include "restock_command.h"

/**
 * Construct a command file object.
 *
 * @param filePath Path to the command file.
 */
CommandFile::CommandFile(std::string filePath)
	: file_path{std::move(filePath)}
{
}

/**
 * Read the command file to produce a list of commands based on its contents.
 *
 * @return A list of command objects read from the file.
 */
std::vector<std::shared_ptr<Command>> CommandFile::commands()
{
	if (!parsed)
	{
		parseFile();
	}

	return file_commands;
}

/**
 * Provide all the errors encountered while parsing the file.
 *
 * @return A list of all parsing errors.
 */
std::vector<std::shared_ptr<std::runtime_error>> CommandFile::errors()
{
	if (!parsed)
	{
		parseFile();
	}

	return file_errors;
}

/**
 * Parse the file and store its contents in the cache.
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

		if (std::regex_search(line, inventory_match, inventory_pattern))
		{
			file_commands.emplace_back(
				std::shared_ptr<Command>{new InventoryCommand{}});
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
			auto item = parseDVD(line);
			if (!item)
			{
				file_errors.emplace_back(
					std::make_shared<std::runtime_error>(
						"[Command Parser] " + line
				));
			}
			else
			{
				file_commands.emplace_back(
					std::shared_ptr<Command>{new BorrowCommand{
						stoi(borrow_match[1]),
						std::make_unique<DVD>(*item)
				}});
			}
		}
		else if (std::regex_search(line, return_match, return_pattern))
		{
			auto item = parseDVD(line);
			if (!item)
			{
				file_errors.emplace_back(
					std::make_shared<std::runtime_error>(
						"[Command Parser] " + line
				));
			}
			else
			{
				file_commands.emplace_back(
					std::shared_ptr<Command>{new RestockCommand{
						stoi(return_match[1]),
						std::make_unique<DVD>(*item)
				}});
			}
		}
		else
		{
			file_errors.emplace_back(
				std::make_shared<std::runtime_error>(
					"[Command Parser] " + line
			));
		}
	}

	parsed = true;
}

/**
 * Parse a line in the file to build the involved DVD object.
 *
 *
 * @param line The line in the command file.
 * @return The matching DVD object.
 * @throws If this method fails to match a DVD, it will throw std::runtime_error
 */
DVD CommandFile::parseDVD(const std::string& line)
{
		std::smatch comedy_match;
		std::smatch drama_match;
		std::smatch classic_match;

		if (std::regex_search(line, comedy_match, comedy_pattern))
		{
			return DVD{std::shared_ptr<Movie>{new ComedyMovie(
				"comedy",
				"",
				comedy_match[1],
				stoi(comedy_match[2])
			)}};
		}
		else if (std::regex_search(line, drama_match, drama_pattern))
		{
			return DVD{std::shared_ptr<Movie>{new DramaMovie(
				"drama",
				drama_match[1],
				drama_match[2],
				-1
			)}};
		}
		else if (std::regex_search(line, classic_match, classic_pattern))
		{
			return DVD{std::shared_ptr<Movie>{new ClassicMovie(
				"classic",
				"",
				"",
				stoi(classic_match[2]),
				stoi(classic_match[1]),
				classic_match[3]
			)}};
		}
		else
		{
			throw std::runtime_error("No matching DVD format");
		}
}
