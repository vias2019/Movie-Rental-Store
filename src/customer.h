/**
 * @file customer.h
 * @author Viktoriya Grishkina
 */
#pragma once
#include <string>
#include <vector>
#include "dvd.h"


using namespace std;

class Customer {
public:
   int key;
   string lastName;
   string firstName;
   int indexN;

   struct History {
      char type = '\0';
      DVD *movie;
   };

   vector <History> history;
   
   //a default constructor
   Customer();

   // a constructor
   Customer(int keyInput, const string& lastNameInput, const string& firstNameInput);
};
