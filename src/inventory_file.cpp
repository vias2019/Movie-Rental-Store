/**
 * @file inventory_file.cpp
 * @author Dominic Ewing
 */

#include "inventory_file.h"

/**
 * Construct an inventory file object.
 *
 * @param filePath Path to the inventory file.
 */
explicit InventoryFile::InventoryFile(std::string filePath)
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
}

/**
 * Provide all the errors encountered while parsing the file.
 *
 * @return A list of all parsing errors.
 */
std::vector<RentalSystemError> errors() const
{
}
