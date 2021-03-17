/**
 * @file customer.h
 * @author Viktoriya Grishkina
 */
#pragma once
#include <string> // string
#include <vector> // vector
#include "dvd.h"


using namespace std;
/**
* Creates a customer record - object, which stores key, lastname, and first 
* name, history of transactions, and erray index number.
**/
class Customer {
public:
   int key;
   string lastName;
   string firstName;
   int indexN;

   // Store inforamation about transaction: type (borrow or return) and movie 
   // name pointer
   struct History {
      char type = '\0';
      DVD *movie;
   };

   // All transactions are stored in vector of objects
   vector <History> history;
   
   // Constructor
   Customer();

   // Copy constructor
   Customer(int keyInput, const string& lastNameInput, 
   	const string& firstNameInput);
};
