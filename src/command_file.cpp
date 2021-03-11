/**
 * @file command_file.cpp
 * @author Dominic Ewing
 */

#include "command_file.h"

/**
 * Construct a command file object.
 *
 * @param filePath Path to the command file.
 */
CommandFile::CommandFile(std::string filePath)
	: file_path{std::move(filePath)}
{
}

/**
 * Read the command file to produce a list of commands based on its contents.
 *
 * @return A list of command objects read from the file.
 */
std::vector<Command> CommandFile::commands() const
{
	return {};
}

/**
 * Provide all the errors encountered while parsing the file.
 *
 * @return A list of all parsing errors.
 */
std::vector<std::runtime_error> CommandFile::errors() const
{
	return {};
}
