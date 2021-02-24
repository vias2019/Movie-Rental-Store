/**
 * @file customer_file.hpp
 * @author Dominic Ewing
 */

#ifndef RENTAL_SYSTEM_CUSTOMER_FILE_HPP
#ifndef RENTAL_SYSTEM_CUSTOMER_FILE_HPP

#include <string>
#include <vector>

#include "clientele.hpp"
#include "rental_system_error.hpp"

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
