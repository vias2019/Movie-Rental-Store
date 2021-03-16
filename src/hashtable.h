/**
 * @file hashtable.h
 * @author Viktoriya Grishkina
 */
#pragma once
#include <string>
#include <vector>
#include "customer.h"
#include "dvd.h"

using namespace std;



class HashTable {
private:
   static const int capacity = 15;
   
   //number of entries
   int size = 0;
   Customer arr[capacity];

   //to find index for a key
   int getHashCode(int key);

public:
   
   HashTable();
   ~HashTable();

   //insert an entry
   void insert(int key, const string& fn, const string& ln);

   //check quantity
   int checkQuantity(int key, DVD& code);

   //deletes data
   void deleteData(int key);

   //searches for the data
   Customer findCustomer(int key);

   // gets the number of customers in the hash table
   int getSize();

   //print transactions by a customer
   void printTransactions(int key);
   
   // records borrow transactions by adding an object {type, itemCode} in 
   // "history" vector
   void borrow(int key, DVD& movie ); // add quantity int& itemCode

   // returns itemCode if movie is rented by the customer
   // and throws an error if movie is not found
   DVD& restock(int key, DVD& movie);
};
