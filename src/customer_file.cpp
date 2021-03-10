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
CustomerFile::CustomerFile(string filePath)
	: file_path{move(filePath)}
{
}

/**
 * Read the customer file to produce a Clientle object representing all the
 * customers described in the file.
 *
 * @return The Clientele represented by the file contents.
 */
HashTable CustomerFile::customers() const
{
   HashTable nova; // should be updated
   return nova;
}

/**
 * Provide all the errors encountered while parsing the file.
 *
 * @return A list of all parsing errors.
 */
//std::vector<RentalSystemError> errors() const
//{
//}
