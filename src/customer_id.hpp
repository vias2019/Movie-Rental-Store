/**
 * @file customer_id.hpp
 * @author Dominic Ewing
 */

#ifndef RENTAL_SYSTEM_CUSTOMER_ID_HPP
#define RENTAL_SYSTEM_CUSTOMER_ID_HPP

/**
 * Represents a customer ID number in the system.
 */
class CustomerID
{
public:
	explicit CustomerID(int number);

private:
	int id;
};

#endif
