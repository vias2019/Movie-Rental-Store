/**
 * @file rental_system_error.h
 * @author Dominic Ewing
 */

#ifndef RENTAL_SYSTEM_ERROR_H
#define RENTAL_SYSTEM_ERROR_H

#include <exception>	// Inheriting from std::runtime_error

/**
 * Basic error class for reporting failed rental operations.
 */
class RentalSystemError : public std::runtime_error
{
};

#endif
