/**
 * @file hashtable.h
 * @author Viktoriya Grishkina
 */
#pragma once
#include <string> // string
#include <vector> // vector
#include "customer.h"
#include "dvd.h"

using namespace std;

/**
* Builds a hashtable for Customer list
**/


class HashTable {
private:
   static const int capacity = 15;
   
   // Number of entries in the hashtable
   int size = 0;

   // HashTable vector 
   Customer arr[capacity];

   // To find index for a key
   int getHashCode(int key);

public:
   
   
   // Insert an entry
   void insert(int key, const string& fn, const string& ln);

   // Check quantity
   int checkQuantity(int key, DVD& code);

   // Deletes data
   void deleteData(int key);

   // Searches for the data
   Customer findCustomer(int key);

   // Gets the number of customers in the hash table
   int getSize();

   // Prints transactions by a customer
   void printTransactions(int key);
   
   // Records borrow transactions by adding an object {type, itemCode} in 
   // "history" vector
   void borrow(int key, DVD& movie ); 

   // Returns itemCode if movie is rented by the customer
   // and throws an error if movie is not found
   DVD& restock(int key, DVD& movie);
};
