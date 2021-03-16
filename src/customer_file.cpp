/**
 * @file customer_file.cpp
 * @author Viktoriya Grishkina
 */

#include <string>
#include "customer_file.h"

using namespace std;
/**
 * Construct a customer file object.
 *
 * @param filePath Path to the customer file.
 */
//CustomerFile::CustomerFile(string filePath)
//	: file_path{move(filePath)}
//{
//   readFile(filePath);
//}

/**
 * Read the customer file to produce a Clientle object representing all the
 * customers described in the file.
 *
 * @return The Clientele represented by the file contents.
 */

HashTable CustomerFile::readFile(string file_path, HashTable& nova)
{
   ifstream file(file_path);
   //HashTable nova;
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


/**
 * Provide all the errors encountered while parsing the file.
 *
 * @return A list of all parsing errors.
 */
//std::vector<RentalSystemError> errors() const
//{
//}
