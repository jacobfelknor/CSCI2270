#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "HashTable.hpp"


int main(int argc, char *argv[]){

	if(argc != 5){
		cout << "Usage: Assignment7Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt> <size of hash table>" << endl;
		exit(0);
	}

	HashTable wordsTable(stoi(argv[4]));
	HashTable stopWordsTable(STOPWORD_TABLE_SIZE);

	getStopWords(argv[3], stopWordsTable); // fill hash with stop words

	ifstream inStream;
	inStream.open(argv[2]);
	string tempWord;

	stringstream ss;
	string line;

	if(inStream.is_open()){
		while(getline(inStream, line)){
			ss << line;
			while(ss >> tempWord){
			    
    			if(!stopWordsTable.isInTable(tempWord)){
    			
    			    wordsTable.addWord(tempWord);
    			    
    			}
    		}
			    
				    

			ss.clear();
		}

		inStream.close();
        wordsTable.printTopN(stoi(argv[1]));
		//wordsTable.printTopN(stoi(argv[1]));
		cout << "#" << endl << "Number of collisions: " << wordsTable.getNumCollisions() << endl;
		cout << "#" << endl << "Unique non-stop words: " << wordsTable.getNumItems() << endl;
		cout << "#" << endl << "Total non-stop words: " << wordsTable.getTotalNumWords() << endl;
	}else{
		cout << "Failed to open " << argv[2] << endl;
		exit(0);
	}
	


	return 0;
}