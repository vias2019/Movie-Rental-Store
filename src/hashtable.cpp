#include <iostream>
#include <vector>
#include "hashTable.h"
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

//Customer::History HashTable::buildHistory(char type, int& movieCode)
//{
//   Customer::History nova;
//   nova.type = type; 
//   nova.quantity++;
//   nova.movieCode = &movieCode;
//   return nova;
//}

int HashTable::checkQuantity(int key, int& code)
{
   int quantity = 0;
   Customer temp = findCustomer(key);
   if (temp.key != -1) {
      for (int i = 0; i < temp.history.size(); i++) {
         if (temp.history[i].movieCode == &code && temp.history[i].type == 'B') {
            quantity = quantity + temp.history[i].quantity;
         }
      }
   }
   return quantity;
}

void HashTable::insert(int key, string fn, string ln)
{
   Customer temp(key, fn, ln);
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
   }
}

void HashTable::deleteData(int key) {
   Customer cust = findCustomer(key);
   if (cust.key == key) {
      arr[cust.indexN].key = -1;
      arr[cust.indexN].firstName = "";
      arr[cust.indexN].lastName = "";
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
      for (int i = 0; i < temp.history.size(); i++) {
         cout << temp.history[i].type << ":    " << temp.history[i].quantity << "     " << *temp.history[i].movieCode << endl;
      }
   }
   else {
      cout << "There are no records for this customer code." << endl;
   }
}

void HashTable::borrow(int key, char command, int quantity, int& itemCode) // Public item& Return (Command command, item& item); 
{
   Customer temp = findCustomer(key);
   Customer::History nova;
   nova.type = command;
   nova.quantity = quantity;
   nova.movieCode = &itemCode;
   arr[temp.indexN].history.push_back(nova);
}

bool HashTable::returnMovie(int key, char command, int quantity, int& itemCode)
{
   Customer temp = findCustomer(key);
   int rented = checkQuantity(key, itemCode);

   cout << "quantity: " << rented << endl;
   if (rented != 0 && rented <= quantity) {
      Customer temp = findCustomer(key);
      Customer::History nova;
      nova.type = command;
      nova.quantity = -quantity;
      nova.movieCode = &itemCode;
      arr[temp.indexN].history.push_back(nova);
      return true;
   }
   else { 
      cout << "Item either not rented or quantity is wrong" << endl;
      return false; }
   
}

int HashTable::getSize()
{
   return size;
}



