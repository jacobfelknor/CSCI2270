#include <iostream>
#include <string>
using namespace std;

struct Student{
	string name;
	int sid;
};


int hashSum(string key, int keyLength, int tableSize){
	int sum = 0;
	for(int i = 0; i < keyLength; i++){
		sum = sum + key[i];
	}


	return sum%tableSize;
}
	

int main(){
	//create a hash table
	int hashSize = 4;
	Student hashTable[hashSize];

	//store records in the hash table

	//create a record
	Student sIn;
	sIn.name = "anna";
	sIn.sid = 823;
	int index = hashSum(sIn.name, 4, hashSize);

	cout << "index for " << sIn.name << " = " << index << endl;

	hashTable[index] = sIn;

	//Retrieve record from a hash table
	//calculate the index

	Student sOut = hashTable[hashSum("anna", 4, hashSize)];


	return 0;
}