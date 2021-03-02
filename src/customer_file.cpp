/**
 * @file customer_file.cpp
 * @author Dominic Ewing
 */

#include "customer_file.h"

/**
 * Construct a customer file object.
 *
 * @param filePath Path to the customer file.
 */
explicit CustomerFile::CustomerFile(std::string filePath)
	: file_path{std::move(filePath)}
{
}

/**
 * Read the customer file to produce a Clientle object representing all the
 * customers described in the file.
 *
 * @return The Clientele represented by the file contents.
 */
Clientele CustomerFile::customers() const
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
