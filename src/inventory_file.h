/**
 * @file inventory_file.h
 * @author Dominic Ewing
 */

#ifndef INVENTORY_FILE_H
#define INVENTORY_FILE_H

#include <string>
#include <vector>

#include "inventory.h"

/**
 * Represents an inventory file. The file can be parsed to create an inventory
 * object in memory.
 */
class InventoryFile
{
	explicit InventoryFile(std::string filePath);

	Inventory inventory() const;
	std::vector<std::runtime_error> errors() const;

private:
	std::string file_path;
};

#endif
