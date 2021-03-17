/**
 * @file customer.cpp
 * @author Viktoriya Grishkina
 */
#include "customer.h"

// Assign default values for a constractor
Customer::Customer()
{
   key = -1;
   lastName = "";
   firstName = "";
   indexN = -1;
}

// Assign values for a copy constractor
Customer::Customer(int keyInput, const string& lastNameInput, 
	const string& firstNameInput)
{
   key = keyInput;
   lastName = lastNameInput;
   firstName = firstNameInput;
}
