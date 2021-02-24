/**
 * @file inventory_file.hpp
 * @author Dominic Ewing
 */

#ifndef RENTAL_SYSTEM_INVENTORY_FILE_HPP
#ifndef RENTAL_SYSTEM_INVENTORY_FILE_HPP

#include <string>
#include <vector>

#include "inventory.hpp"
#include "rental_system_error.hpp"

/**
 * Represents an inventory file. The file can be parsed to create an inventory
 * object in memory.
 */
class InventoryFile
{
	explicit InventoryFile(std::string filePath);

	Inventory inventory() const;
	std::vector<RentalSystemError> errors() const;

private:
	std:string file_path;
};

#endif
