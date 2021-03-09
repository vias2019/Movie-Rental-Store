/**
 * @file customer_id.h
 * @author Dominic Ewing
 */

#ifndef CUSTOMER_ID_H
#define CUSTOMER_ID_H

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
