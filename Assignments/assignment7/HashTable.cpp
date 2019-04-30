#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

#include "HashTable.hpp"

int totalWords = 0;

bool inArray(wordItem **topWords, int n, string key){
	for(int i = 0; i < n; i++){
		if(topWords[i]->word == key)
			return true;
	}

	return false;
}


void sortArray(wordItem **topWords, int length){
	wordItem *temp;
	for(int i = length-1; i>0; i--){
			for(int j = 0; j<i; j++){
				if(topWords[j]->count < topWords[j+1]->count){
					temp = topWords[j];
					topWords[j] = topWords[j+1];
					topWords[j+1] = temp;
				}
			}

	}
}

int getMin(wordItem** topWords, int n){
	int minIndex = 0;
	for(int i = 0; i < n; i++){
		if(topWords[i]->count < topWords[minIndex]->count){
			minIndex = i;
		}
	}

	return minIndex;
}


void topWordHelper(wordItem** hashTable, int hashTableSize, wordItem **topWords, int n){
	int j = 0;
	int i = 0;
	int k = 0;
	bool check1 = true;
	wordItem *min;
	int minIndex;

			while(j < n)
			{
				wordItem *temp1 = hashTable[i];
				while(temp1 != nullptr && j < n)
				{
					topWords[j] = temp1;
					j++;
					temp1 = temp1->next;
			    }
			    i++;
		   }
		

	minIndex = getMin(topWords, n);
	min = topWords[minIndex];

	for(int i = 0; i < hashTableSize; i++){
		if(hashTable[i] != nullptr)
		{
			if(hashTable[i]->count > min->count)
			{
				if(!inArray(topWords, n, hashTable[i]->word))
				{
					topWords[minIndex] = hashTable[i];
					minIndex = getMin(topWords, n);
					min = topWords[minIndex];
				}
			}	
			
			wordItem *temp = hashTable[i];
			while(temp->next != nullptr){
				if(temp->count > min->count){
					if(!inArray(topWords, n, temp->word)){
						topWords[minIndex] = temp;
						minIndex = getMin(topWords, n);
						min = topWords[minIndex];
					}
				}	
				temp = temp->next;
			}
			
		}
			
	}

}


HashTable::HashTable(int hashTableSize){
	hashTable = new wordItem*[hashTableSize];
	for(int i = 0; i < hashTableSize; i++){
		//cout << hashTable[i] << endl;
		hashTable[i] = nullptr;
	}

	this->hashTableSize = hashTableSize;
	numItems = 0;
	numCollisions = 0;



}

HashTable::~HashTable(){
	//need more up here...interate?
	delete []hashTable;
}

void HashTable::addWord(string word){
	if(isInTable(word)){
		incrementCount(word);
		totalWords++;
	}else{
		int index = getHash(word);
		numItems++;
		totalWords++;
		if(hashTable[index] == nullptr){
			hashTable[index] = new wordItem;
			hashTable[index]->word = word;
			hashTable[index]->count = 1;
			hashTable[index]->next = nullptr;
		}else{
			numCollisions++;
			wordItem *temp = hashTable[index];
			wordItem *prev;
			while(temp != nullptr){
				prev = temp;
				temp = temp->next;
			}
			//temp = nullptr;
			temp = new wordItem;
			temp->word = word;
			temp->count = 1;
			temp->next = nullptr;
			prev->next = temp;
		}
	}
	
}

bool HashTable::isInTable(string word){
	if(searchTable(word) == nullptr){
		return false;
	}else{
		return true;
	}
}

void HashTable::incrementCount(string word){
	wordItem *foundWord = searchTable(word);
	if(foundWord != nullptr){
		foundWord->count++;
	}

}


void HashTable::printTopN(int n){
	wordItem **topWords = new wordItem*[n];
	topWordHelper(hashTable, hashTableSize, topWords, n);
	sortArray(topWords, n);

	for(int i = 0; i < n; i++){
		cout << fixed << setprecision(4) << (float)topWords[i]->count/totalWords << " - " << topWords[i]->word << endl;
	}

}

int HashTable::getNumCollisions(){
	return numCollisions;
}

int HashTable::getNumItems(){
	return numItems;
}

int HashTable::getTotalNumWords(){
	int totalWords = 0;
	for(int i = 0; i < hashTableSize; i++){
		if(hashTable[i] != nullptr){
			totalWords = totalWords + hashTable[i]->count;
			
			wordItem *temp = hashTable[i];
			while(temp->next != nullptr){
				totalWords = totalWords + temp->next->count;
				temp = temp->next;
			}
			
		}
			
	}

	return totalWords;
}

unsigned int HashTable::getHash(string word){
	unsigned int hashValue = 5381;
	int length = word.length();
	for(int i = 0; i < length; i++){
		hashValue=((hashValue<<5) + hashValue) + word[i];
	}

	hashValue %= hashTableSize;

	return hashValue;
}

wordItem* HashTable::searchTable(string word){
	int index = getHash(word);
	if(hashTable[index] == nullptr){
		return nullptr;
	}else if(hashTable[index]->word == word){
		return hashTable[index];
	}else{
		wordItem *temp = hashTable[index];
		while(temp != nullptr && temp->word != word){
			temp = temp->next;
		}
		return temp;
	}
}



void getStopWords(char *ignoreWordFileName, HashTable &stopWordsTable){
	ifstream ignoreStream;
	ignoreStream.open(ignoreWordFileName);

	if(ignoreStream.is_open()){
		string tempWord;
		while(ignoreStream >> tempWord){
			stopWordsTable.addWord(tempWord);
		}
	}else{
		cout << "Failed to open " << ignoreWordFileName << endl;
		exit(0);
	}

	ignoreStream.close();
}

bool isStopWord(string word, HashTable &stopWordsTable){
	if(stopWordsTable.isInTable(word)){
		return true;
	}

	return false;
}