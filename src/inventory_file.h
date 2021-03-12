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

	Inventory inventory() const;
	std::vector<std::runtime_error> errors() const;

private:
	std::string file_path;

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
		"([[:alpha:]]+) "		// major actor first name
		"([[:alpha:]]+) "		// major actor last name
		"([[:digit:]]+) "		// release month
		"([[:digit:]]+)"		// release year
	};
};

#endif
