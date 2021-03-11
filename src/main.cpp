// Assignment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "customer.h"
#include "customer_file.h"
#include "hashtable.h"

using namespace std;

int main()
{
   //======================= Viktoriya's tests======================================================
   CustomerFile Nova;
   
   HashTable M;
   Nova.readFile("data4customers.txt", M);
   M.insert(6, "Vika", "Gri");
   M.insert(8, "Dasha", "Mo");
   Customer v = M.findCustomer(3);
   int size = M.getSize();
   DVD movie1;
   DVD movie2;

   M.borrow(6, movie1);
   M.borrow(6, movie2);
  //M.restock(6, movie1);
  // cout << "Print quantity: " << M.checkQuantity(6, movie1) << endl;
   M.printTransactions(6);
 
   //M.deleteData(3);
   //=================================================================================================
   std::cout << "Hello World!\n";
}

