/**
 * @file customer_file.h
 * @author Viktoriya Grishkina
 */

#ifndef CUSTOMER_FILE_H


#include <string>
#include <vector>
#include <fstream>

#include "hashtable.h"
using namespace std;
//#include "rental_system_error.h"


/**
 * Represents an customer file. The file can be parsed to create a Clientele
 * object aggregating all the represented in the file.
 */
class CustomerFile
{
	/*explicit CustomerFile(std::string filePath);*/

	//HashTable customers(int key, string ln, string fn) const;
	//std::vector<RentalSystemError> errors() const;

private:
	std::ifstream file_path;

public:
   	HashTable readFile(string file_path, HashTable& nova);
};

#endif
