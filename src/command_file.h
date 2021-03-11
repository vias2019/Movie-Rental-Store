/**
 * @file command_file.h
 * @author Dominic Ewing
 */

#ifndef COMMAND_FILE_H
#define COMMAND_FILE_H

#include <stdexcept>
#include <string>
#include <vector>

#include "command.h"

/**
 * Represents an command file. The file can be parsed to create a list of
 * command objects.
 */
class CommandFile
{
	explicit CommandFile(std::string filePath);

	std::vector<Command> commands() const;
	std::vector<std::runtime_error> errors() const;

private:
	std::string file_path;
};

#endif
