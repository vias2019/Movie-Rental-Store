/**
 * @file customer_file.cpp
 * @author Viktoriya Grishkina
 */

#include <string>
#include "customer_file.h"

using namespace std;


/**
 * Read the customer file to produce a HashTable object representing all the
 * customers described in the file.
 *
 * @return The HashTable represented by the file contents.
 */

HashTable CustomerFile::readFile(string file_path, HashTable& nova)
{
   ifstream file(file_path);
   string line;
   int code;
   string ln;
   string fn;
   
   if (file.eof()) {
      throw runtime_error("message");
   }

   file >> line;
   while (!file.eof() || line == "") {
      
      code = stoi(line);
      file >> line;
      ln = line;
      file >> line;
      fn = line;
      nova.insert(code, ln, fn);
      file >> line;
   }
   return nova;
}


