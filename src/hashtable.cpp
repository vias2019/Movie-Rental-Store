/**
 * @file hashtable.cpp
 * @author Viktoriya Grishkina
 */
#include <iostream> // input/output
#include <vector> // vector
#include "hashtable.h"
#include "item.h"
using namespace std;


// Gets a hash key number
int HashTable::getHashCode(int key)
{
    return (key % capacity);
}

// Checks quantity of movies, facilitates restock function
int HashTable::checkQuantity(int key, DVD& movie)
{
   int quantity = 0;
   Customer temp = findCustomer(key);
   if (temp.key != -1) {
      for (size_t i = 0; i < temp.history.size(); i++) {
         if (temp.history[i].movie->compare(movie) == 0 && 
         temp.history[i].type == 'B') {
            quantity++;
         }
         else if (temp.history[i].movie->compare(movie) == 0 && 
         temp.history[i].type == 'R') {
            quantity--;
         }
      }
   }
   return quantity;
}

// Insert an entry in the Hashtable
void HashTable::insert(int key, const string& ln, const string& fn)
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

// Deletes data in the Customer list
void HashTable::deleteData(int key) {
   Customer cust = findCustomer(key);
   if (cust.key == key) {
      arr[cust.indexN].key = -1;
      arr[cust.indexN].lastName = "";
      arr[cust.indexN].firstName = "";
      arr[cust.indexN].indexN = -1;
      arr[cust.indexN].history.clear();
      size--;
   } else {
      throw runtime_error("Item either not in the list or key is wrong");
   }
}

// Finds a customer using a hash key
Customer HashTable::findCustomer(int key) {
   Customer value;
   int hashIndex = getHashCode(key);

   while(arr[hashIndex].key != -1){
      if(arr[hashIndex].key == key){
         return arr[hashIndex];
      } else {
         hashIndex++;
      }
   }
   if (arr[hashIndex].key == -1){
      throw std::runtime_error("Customer " + to_string(key) 
      + " does not exist");
   }
   
   return value;
}

// Prints selected customer's transactions
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

// Processes borrow transaction, stores a record in history vector 
// under a specific customer
void HashTable::borrow(int key, DVD& movie ) 
{
   Customer temp = findCustomer(key);
   Customer::History nova;

   nova.type = 'B';
   nova.movie = &movie;
   arr[temp.indexN].history.push_back(nova);
}

// Processes restock transaction, checks quantity before return
// to make sure that the returned item was borrowed;
// stores a record in History vector under a customer
DVD& HashTable::restock(int key, DVD& movie) 
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
      throw runtime_error("Item either not rented or quantity is wrong");
   }
   
}

// Returns the size/number of customers
int HashTable::getSize()
{
   return size;
}



