/**
 * @file inventory_file.cpp
 * @author Dominic Ewing
 */

#include <fstream>

#include "inventory_file.h"

/**
 * Construct an inventory file object.
 *
 * @param filePath Path to the inventory file.
 */
InventoryFile::InventoryFile(std::string filePath)
	: file_path{std::move(filePath)}
{
}

/**
 * Create an inventory object representing the contents of the file.
 *
 * @return An inventory object representing the contents of the file.
 */
Inventory InventoryFile::inventory() const
{
	ifstream stream{file_path};
	Inventory inventory;

	for (std::string line; std::getline(stream, line); )
	{
		std::smatch comedy_match;
		std::smatch drama_match;
		std::smatch classic_match;

		if (std::regex_search(line, comedy_match, comedy_pattern))
		{
			const int quantity = stoi(comedy_match[1]);
			ComedyMovie movie  {
				"comedy",
				comedy_match[2],
				comedy_match[3],
				stoi(comedy_match[4])
			};

			DVD dvd (movie);

			inventory.addStock(
				dvd,
				quantity
			);

			std::cout << "comedy:   " << movie.toString() << '\n';
		}
		else if (std::regex_search(line, drama_match, drama_pattern))
		{
			std::cout << "drama:    " << line << '\n';
		}
		else if (std::regex_search(line, classic_match, classic_pattern))
		{
			std::cout << "classic:  "<< line << '\n';
		}
		else
		{
			std::cout << "no match: " << line << '\n';
		}
	}

	return inventory;
}

/**
 * Provide all the errors encountered while parsing the file.
 *
 * @return A list of all parsing errors.
 */
std::vector<std::runtime_error> InventoryFile::errors() const
{
	return {};
}
