/**
 * @file hashtable.cpp
 * @author Viktoriya Grishkina
 */
#include <iostream>
#include <vector>
#include "hashtable.h"
#include "item.h"
using namespace std;


HashTable::HashTable()
{
}

HashTable::~HashTable()
{
}

int HashTable::getHashCode(int key)
{
    return (key % capacity);
}

int HashTable::checkQuantity(int key, DVD& movie)
{
   int quantity = 0;
   Customer temp = findCustomer(key);
   if (temp.key != -1) {
      for (size_t i = 0; i < temp.history.size(); i++) {
         if (temp.history[i].movie->compare(movie) == 0 && temp.history[i].type == 'B') {
            quantity++;
         }
         else if (temp.history[i].movie->compare(movie) == 0 && temp.history[i].type == 'R') {
            quantity--;
         }
      }
   }
   return quantity;
}

void HashTable::insert(int key, string ln, string fn)
{
   Customer temp(key, ln, fn);
   int hashIndex = getHashCode(key);
   
   if (arr[hashIndex].key == -1) {
      arr[hashIndex] = temp;
      arr[hashIndex].indexN = hashIndex;
      size++;
   }
   else {
      while (arr[hashIndex].key != -1) {
         hashIndex++;
      }
      arr[hashIndex] = temp;
      arr[hashIndex].indexN = hashIndex;
      size++;
   }
}

void HashTable::deleteData(int key) {
   Customer cust = findCustomer(key);
   if (cust.key == key) {
      arr[cust.indexN].key = -1;
      arr[cust.indexN].lastName = "";
      arr[cust.indexN].firstName = "";
      arr[cust.indexN].indexN = -1;
      arr[cust.indexN].history.clear();
   }
}

Customer HashTable::findCustomer(int key) {
   Customer value;
   for (int i = 0; i < capacity; i++) {
      if (arr[i].key == key) {
         cout << "found" << endl;
         return arr[i];
      }
   }
   cout << "not found" << endl;
   return value;
}

void HashTable::printTransactions(int key)
{
   Customer temp = findCustomer(key);
   if (temp.key != -1) {
      cout << endl;
      cout << "Transactions by a customer # " << key << ":" << endl;
      for (size_t i = 0; i < temp.history.size(); i++) {
         cout << temp.history[i].type << ":    ";
         temp.history[i].movie->getMovie();
         cout << endl;
      }
   }
   else {
      cout << "There are no records for this customer code." << endl;
   }
}

void HashTable::borrow(int key, DVD& movie ) // Public item& Return (Command command, item& item); //transaction object //int& itemCode
{
   Customer temp = findCustomer(key);
   Customer::History nova;
   nova.type = 'B';
   nova.movie = &movie;
   arr[temp.indexN].history.push_back(nova);
}

DVD& HashTable::restock(int key, DVD& movie) // remove quantity
{
   Customer temp = findCustomer(key);
   int quantity = checkQuantity(key, movie);
   if (temp.key != -1 && quantity > 0) {
      Customer::History nova;
      nova.type = 'R';
      nova.movie = &movie;
      arr[temp.indexN].history.push_back(nova);
      return movie;
   }
   else 
   { 
      //cout << "Item either not rented or quantity is wrong" << endl;
      throw runtime_error("Item either not rented or quantity is wrong");
   }
   
}

int HashTable::getSize()
{
   return size;
}



