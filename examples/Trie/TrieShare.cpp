// code adapted from https://www.geeksforgeeks.org/trie-insert-and-search/

#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode{
	TrieNode *children[ALPHABET_SIZE];

	bool isEndOfWord;
};



int main(){

	// Test keys. Using only ASCII characters a through z
	string keys[] = {"the","a","there","answer","any","by","bye","their"};
	int n = 8;

	// The first node gets created here
	// TrieNode *root = makeNode();

	// for(int i = 0; i<n; i++)
	// 	insert(root,keys[i]);
	// // 
	// string searchString;

	// while(searchString!="exit"){
	// 	cout << "Input a search string to see if it's in the dictonary: ";
	// 	cin >> searchString;
	// 	cout << "\"" << searchString;
	// 	bool inDictonary =  search(root,searchString);
	// 	if(inDictonary)
	// 		cout << "\" found in dictionary" << endl;
	// 	else
	// 		cout << " not found in dictionary" << endl;
	// }

	return 0;
}

