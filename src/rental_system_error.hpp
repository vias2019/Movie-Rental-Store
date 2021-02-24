/**
 * @file rental_system_error.hpp
 * @author Dominic Ewing
 */

#ifndef RENTAL_SYSTEM_RENTAL_SYSTEM_ERROR
#define RENTAL_SYSTEM_RENTAL_SYSTEM_ERROR

#include <exception>	// Inheriting from std::exception

/**
 * Basic error class for reporting failed rental operations.
 */
class RentalSystemError : public std::runtime_error
{
};

#endif
