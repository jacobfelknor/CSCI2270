#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct wordItem{ //struct to store word information
	string word;
	int count;
};

void getStopWords(const char *ignoreWordFileName, string ignoreWords[]); //function to store
																		//words to ignore
bool isStopWord(string word, string ignoreWords[]); //function to check if word is in
													//ignoreWords array
int getTotalNumberNonStopWords(wordItem uniqueWords[], int length); //store unique words
																	// in an array, return
																	//the # of these words
void arraySort(wordItem uniqueWords[], int length); //sorts the array by word count
void printTopN(wordItem uniqueWords[], int topN, int totalNumWords); //

int main(int argc, char *argv[]){

	if(argc != 4){
		cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
		exit(0);
	}

	string ignoreWords[50]; //create array to store words to ignore


	getStopWords(argv[3], ignoreWords); //fill array with stop words
	int arrSize = 100;
	//declare new array in heap with starting size 100. will double if filled
	wordItem *wordsPtr = new wordItem[arrSize];
	wordItem *tempPtr;
	//set up input filestream and necessary variables to preform word count
	ifstream wordStream;
	wordStream.open(argv[2]);
	string tempWord;
	int uniqueCount = 0;
	bool check = true;
	int arrayDoubles = 0; 

	//check to make sure file has opened
	if(wordStream.is_open()){
		while(wordStream >> tempWord){

			if((uniqueCount) == arrSize){   //double array size if original fills
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

			if(!isStopWord(tempWord, ignoreWords)){  //check for ignore word
				for(int i = 0; i < arrSize; i++){      //look to see if word is unique
					if(tempWord == wordsPtr[i].word){
						check = false;
						wordsPtr[i].count++;
						break;
					}
				}

				if(check){								//if word is unique, add it to 
					wordsPtr[uniqueCount].word = tempWord;  //array and iterate count
					wordsPtr[uniqueCount].count = 1;
					uniqueCount++;
				}

				check = true;
			}  
		}

		int totalNumWords = getTotalNumberNonStopWords(wordsPtr, uniqueCount);

		arraySort(wordsPtr, uniqueCount); //sort array based on word count


		//display important information to the user
		cout << "Array doubled: " << arrayDoubles << endl << "#" << endl;
		cout << "Unique non-common words: " << uniqueCount << endl << "#" << endl;
		cout << "Total non-common words: " << totalNumWords << endl << "#" << endl;

		cout << "Probabilities of top " << argv[1] << " most frequent words" << endl;
		cout << "---------------------------------------" << endl;
		printTopN(wordsPtr, stoi(argv[1]), totalNumWords); //prints top user specified number of
												// words to the console

		delete [] wordsPtr;

		
	}else{
		cout << "Failed to open " << argv[2] << endl;
		exit(0);
	}

	
	
	return 0;
}


void getStopWords(const char *ignoreWordFileName, string ignoreWords[]){
	ifstream ignoreStream;
	ignoreStream.open(ignoreWordFileName);

	if(ignoreStream.is_open()){
		int i = 0;
		while(ignoreStream >> ignoreWords[i]){
			i++;
		}
	}else{
		cout << "Failed to open " << ignoreWordFileName << endl;
		exit(0);
	}

	ignoreStream.close();
}


bool isStopWord(string word, string ignoreWords[]){
	bool check = false;
	for(int i = 0; i < 50; i++){
		if(word == ignoreWords[i]){
			check = true;
			break;
		}
	}

	return check;
}


int getTotalNumberNonStopWords(wordItem uniqueWords[], int length){
	int total = 0;
	for(int i = 0; i < length; i++){
		total = total + uniqueWords[i].count;
	}

	return total;

}


void arraySort(wordItem uniqueWords[], int length){
	wordItem temp;
	for(int i = length-1; i>0; i--){
			for(int j = 0; j<i; j++){
				if(uniqueWords[j].count < uniqueWords[j+1].count){
				temp = uniqueWords[j];
				uniqueWords[j] = uniqueWords[j+1];
				uniqueWords[j+1] = temp;
				}
			}

		}
}


void printTopN(wordItem uniqueWords[], int topN, int totalNumWords){
	for(int i = 0; i < topN; i++){
		cout << fixed << setprecision(4) << (float)uniqueWords[i].count/totalNumWords << " - ";
		cout << uniqueWords[i].word << endl;
	}
}