/**
 * @file customer.cpp
 * @author Viktoriya Grishkina
 */
#include "customer.h"

Customer::Customer()
{
   key = -1;
   lastName = "";
   firstName = "";
   indexN = -1;
}

Customer::Customer(int keyInput, const string& lastNameInput, 
	const string& firstNameInput)
{
   key = keyInput;
   lastName = lastNameInput;
   firstName = firstNameInput;
}
