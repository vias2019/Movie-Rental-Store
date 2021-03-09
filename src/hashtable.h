#pragma once
#include <string>
#include <vector>
#include "customer.h"
using namespace std;



class HashTable {
private:
   static const int capacity = 5;
   
   //number of entries
   int size = 0;
   Customer arr[capacity];

   // To save an element number for findCustomer() function
   //int elementNumber = 0;

   //to find index for a key
   int getHashCode(int key);

   //// To build an object stored in a vector
   //Customer::History buildHistory(char type, int& movieCode);
   
   //check quantity
   int checkQuantity(int key, int& code);

public:
   
   HashTable();
   ~HashTable();

   //insert an entry
   void insert(int key, string fn, string ln);

   //deletes data
   void deleteData(int key);

   //searches for the data
   Customer findCustomer(int key);

   int getSize();

   //print transactions by a customer
   void printTransactions(int key);
   
   void borrow(int key, char command, int quantity, int& itemCode); // add quantity

   bool returnMovie(int key, char command, int quantity, int& itemCode);

   



   

};
