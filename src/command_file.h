/**
 * @file command_file.h
 * @author Dominic Ewing
 */

#ifndef COMMAND_FILE_H
#ifndef COMMAND_FILE_H

#include <string>
#include <vector>

#include "command.h"
#include "rental_system_error.h"

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
