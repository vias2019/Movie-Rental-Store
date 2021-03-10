// Assignment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Customer.h"

#include "HashTable.h"
using namespace std;

int main()
{
   //======================= Viktoriya's tests======================================================
   HashTable M;
   M.insert(6, "Vika", "Gri");
   M.insert(8, "Dasha", "Mo");
   Customer v = M.findCustomer(3);
   int size = M.getSize();
   int movie = 123;
   int* code = &movie;
   int movie1 = 111;
   int* code1 = &movie1;
   int movie2 = 123;
   int* code2 = &movie2;
   M.borrow(6, 'B', *code);
   M.borrow(6, 'B', *code1);
   M.borrow(6, 'B', *code2);
   M.restock(6, 'R', *code1);
   M.printTransactions(6);
 
   //M.deleteData(3);
   //=================================================================================================
   std::cout << "Hello World!\n";
}

