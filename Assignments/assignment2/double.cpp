#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct wordItem{ //struct to store word information
	string word;
	int count;
};


int main(){

	int arrSize = 100;
	//declare new array in heap with starting size 100. will double if filled
	wordItem *wordsPtr = new wordItem[arrSize];
	wordItem *tempPtr;
	//set up input filestream and necessary variables to preform word count;
	int uniqueCount = 0;
	int arrayDoubles = 0; 

	for(int i = 0; i < 7000; i++){
		if((uniqueCount - 1) == arrSize){   //double array size if original fills
				arrSize = 2 * arrSize;
				tempPtr = new wordItem[arrSize];
				for(int i = 0; i < arrSize/2; i++){
					tempPtr[i] = wordsPtr[i];
				}
				delete [] wordsPtr;
				wordsPtr = tempPtr;
				tempPtr = NULL;
				
				arrayDoubles++;
		}
		uniqueCount++;
	}

	cout << arrayDoubles << " " << arrSize << endl;
	return 0;
}