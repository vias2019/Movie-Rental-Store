/**
 * @file inventory_file.h
 * @author Dominic Ewing
 */

#ifndef INVENTORY_FILE_H
#ifndef INVENTORY_FILE_H

#include <string>
#include <vector>

#include "inventory.h"
#include "rental_system_error.h"

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
