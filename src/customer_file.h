/**
 * @file customer_file.h
 * @author Viktoriya Grishkina
 */

#ifndef CUSTOMER_FILE_H


#include <string> // string
#include <vector> // vector
#include <fstream> // parse information from file

#include "hashtable.h"
using namespace std;

/**
 * The .txt file can be parsed to create a Hashtable
 * object aggregating all the represented in the file.
 */
class CustomerFile
{
	
private:
	std::ifstream file_path;

public:
	// Reads data from the txt file and saves it in Customer 
	// hashtable
   	HashTable readFile(string file_path, HashTable& nova);
};

#endif
