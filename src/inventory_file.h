/**
 * @file inventory_file.h
 * @author Dominic Ewing
 */

#ifndef INVENTORY_FILE_H
#define INVENTORY_FILE_H

#include <regex>
#include <string>
#include <vector>

#include "inventory.h"

/**
 * Represents an inventory file. The file can be parsed to create an inventory
 * object in memory.
 */
class InventoryFile
{
public:
	explicit InventoryFile(std::string filePath);

	Inventory inventory();
	std::vector<std::shared_ptr<std::runtime_error>> errors();

private:
	std::string file_path;

	// Cache from previously parsing the file. This prevents re-parsing
	// for each separate call to inventory() and errors().
	bool parsed{false};
	Inventory file_inventory{};
	std::vector<std::shared_ptr<std::runtime_error>> error_list{};

	// Helper method for perfoming file parsing and updating cache.
	void parseFile();

	// Since the assignment states that the formatting will be correct, parsing
	// this with a regular expression should be ok.
	const std::regex comedy_pattern {
		"F, "				// F for comdedy
		"([[:digit:]]+), "		// stock
		"([[:alpha:][:space:]]+), "	// director
		"([^,]+), "			// title
		"([[:digit:]]+)"		// year
	};

	const std::regex drama_pattern {
		"D, "				// D for drama
		"([[:digit:]]+), "		// stock
		"([[:alpha:][:space:]]+), "	// director
		"([^,]+), "			// title
		"([[:digit:]]+)"		// year
	};

	const std::regex classic_pattern {
		"C, "				// C for classic movie
		"([[:digit:]]+), "		// stock
		"([[:alpha:][:space:]]+), "	// director
		"([^,]+), "			// title
		"([[:alpha:]]+ [[:alpha:]]+) "	// major actor
		"([[:digit:]]+) "		// release month
		"([[:digit:]]+)"		// release year
	};
};

#endif
