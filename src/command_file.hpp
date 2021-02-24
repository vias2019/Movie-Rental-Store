/**
 * @file command_file.hpp
 * @author Dominic Ewing
 */

#ifndef RENTAL_SYSTEM_COMMAND_FILE_HPP
#ifndef RENTAL_SYSTEM_COMMAND_FILE_HPP

#include <string>
#include <vector>

#include "command.hpp"
#include "rental_system_error.hpp"

/**
 * Represents an command file. The file can be parsed to create a list of
 * command objects.
 */
class CommandFile
{
	explicit CommandFile(std::string filePath);

	std::vector<Command> commands() const;
	std::vector<RentalSystemError> errors() const;

private:
	std:string file_path;
};

#endif
