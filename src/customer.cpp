/**
 * @file customer.cpp
 * @author Viktoriya Grishkina
 */
#include "customer.h"

Customer::Customer()
{
   key = -1;
   firstName = "";
   lastName = "";
   indexN = -1;
}

Customer::Customer(int keyInput, string lastNameInput, string firstNameInput)
{
   key = keyInput;
   firstName = firstNameInput;
   lastName = lastNameInput;
}
