/**
 * @file command_file.h
 * @author Dominic Ewing
 */

#ifndef COMMAND_FILE_H
#define COMMAND_FILE_H

#include <memory>
#include <regex>
#include <stdexcept>
#include <string>
#include <vector>

#include "command.h"
#include "dvd.h"

/**
 * Represents an command file. The file can be parsed to create a list of
 * command objects.
 */
class CommandFile
{
public:
	explicit CommandFile(std::string filePath);

	std::vector<std::shared_ptr<Command>> commands();
	std::vector<std::shared_ptr<std::runtime_error>> errors();

private:
	std::string file_path;

	// Cache from previously parsing the file. This prevents re-parsing
	// for each separate call to commands() and errors().
	bool parsed{false};
	std::vector<std::shared_ptr<Command>> file_commands{};
	std::vector<std::shared_ptr<std::runtime_error>> file_errors{};

	// Helper methods for performing file parsing and updating cache.
	void parseFile();
	DVD parseDVD(const std::string& line);

	const std::regex inventory_pattern {
		"I[[:space:]]+$"	// The code I and no other fields.
	};

	const std::regex history_pattern {
		"H "			// The action type H
		"([[:digit:]]{4})"	// The 4-digit customer id
	};

	const std::regex borrow_pattern {
		"B "			// The action type B
		"([[:digit:]]{4})"	// The 4-digit customer id
	};

	const std::regex return_pattern {
		"R "			// The action type R
		"([[:digit:]]{4})"	// The 4-digit customer id
	};

	// At this point all items are DVDs.
	const std::regex comedy_pattern {
		"D F "			// DVD & Movie type F
		"([^,]+), "		// Title
		"([[:digit:]]+)"	// Release Year
	};

	const std::regex drama_pattern {
		"D D "			// DVD & Movie type D
		"([^,]+), "		// Director
		"([^,\r]+)"		// Title
	};

	const std::regex classic_pattern {
		"D C "			// Movie type C
		"([[:digit:]]{1,2}) "	// Release month
		"([[:digit:]]+) "	// Release year
		"([^,\r]+)"		// Actor
	};
};

#endif
