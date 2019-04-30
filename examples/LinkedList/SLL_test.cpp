#include <iostream>
#include <string>
using namespace	std;

#include "SLL.h"

int main(){
	//create an instance of SLL
	SLL l;

	//Define a test string array
	string arr[] = {"jeden", "dwa", "trzy"};
	int arrLen = 3;

	//test the appendNode funciton
	for(int i = 0; i < arrLen; i++){
		l.appendNode(arr[i]);
	}

	l.displayList();


	//test the search memeber function
	//Node *tmp = l.search("dwa");
	//cout << "node found " << tmp->key << endl;

	//test the destructor
	//l.~SLL();
	//l.displayList();

	//test insert
	l.insert("jeden", "jedenipol");
	l.insert("trzy", "cztery");
	l.insert("", "test");
	l.displayList();

	//test delete
	l.deleteNode("cztery");
	l.displayList();

	return 0;
}