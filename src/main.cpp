// Assignment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Customer.h"

#include "HashTable.h"
using namespace std;

int main()
{
   HashTable M;
   M.insert(6, "Vika", "Gri");
   Customer v = M.findCustomer(3);
   int size = M.getSize();
   int movie = 123;
   int* code = &movie;
   int movie1 = 111;
   int* code1 = &movie1;
   int movie2 = 123;
   int* code2 = &movie2;
   M.borrow(6, 'B', 2, *code);
   M.borrow(6, 'B', 1, *code1);
   M.borrow(6, 'B', 3, *code2);
   M.returnMovie(6, 'R', 1, *code1);
   M.printTransactions(6);
 
   //M.deleteData(3);
   std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
