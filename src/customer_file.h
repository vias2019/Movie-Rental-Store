/**
 * @file customer_file.h
 * @author Dominic Ewing
 */

#ifndef CUSTOMER_FILE_H
#define CUSTOMER_FILE_H

#include <string>
#include <vector>

#include "clientele.h"
#include "rental_system_error.h"

/**
 * Represents an customer file. The file can be parsed to create a Clientele
 * object aggregating all the represented in the file.
 */
class CustomerFile
{
	explicit CustomerFile(std::string filePath);

	Clientele customers() const;
	std::vector<RentalSystemError> errors() const;

private:
	std:string file_path;
};

#endif
