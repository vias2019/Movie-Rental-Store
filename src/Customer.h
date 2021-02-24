#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Customer {
public:
   // Constructor
   Customer();

   //Destructor
   ~Customer();

   // To save a customer data to a hash table
   void saveCustData();

   // Print transaction history for a selected customer (list has the following information for every transaction: return R/B, quantity, Movie ID pointer)
   vector<Command> PrintHistory(int cust id);

   // Return function checks if a customer has borrowed the item and quantity agrees. If it is true, the system records transaction in subvector storing the following data: [[R, 2, “War!!”], ..].
   item& Return(Command command, item& item);

   // The function records transaction in sub-vector storing the following data: [[B, 2, “War!!”], ..].
   void Borrow(Command command, item& item);

   // Print history for a specific customer, return a vector consisting of subvectors with the following information: Type of transaction, quantity, and movie ID pointer.
   vector<Command> printRecords();
};
