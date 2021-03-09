#pragma once
#include <string>
#include <vector>

#include "customer.h"
using namespace std;

class Customer {
public:
   int key;
   string firstName;
   string lastName;
   int indexN;

   struct History {
      char type = '\0';
      int quantity = 0;
      int* movieCode;
   };

   vector <Customer::History> history;
   
   //a default constructor
   Customer();

   // a constructor
   Customer(int keyInput, string lastNameInput, string firstNameInput);

   //no need for a destructor??????????????????????????
};
