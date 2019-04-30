#include <iostream>
using namespace std;

#include "binaryST.h"

BinaryST::BinaryST()
{
	root = nullptr;
}

// Insert new node
void BinaryST::insert( int newValue )
{	
	//create a pointer to keep track of prev node
	Node *prev = nullptr;

	//pointer for traversing the tree. Start with root
	Node *temp = root;

	//create a new node
	Node *n = new Node;

	//set all pointers inside n to null. Write new value to the key
	n->parent = nullptr;
	n->leftChild = nullptr;
	n->rightChild = nullptr;
	n->key = newValue;

	//Loop untl we find first empty spot in tree
	//if the tree is empty, then root is null and loop will not run
	while(temp != nullptr){
		//set prev to temp to keep track of last node
		prev = temp;

		//check which way to go
		if(n->key < temp->key){
			temp = temp->leftChild;
		}else{ 
			temp = temp->rightChild;
		}
	}

	//at this point the parent of the new node has been found

	if(prev == nullptr){ //the case being the tree was empty, while loop never ran
		root = n;
	}else if(n->key < prev->key){
		prev->leftChild = n;
		n->parent = prev;
	}else{
		prev->rightChild = n;
		n->parent = prev;
	}




}

void BinaryST::disp( string Order )
{
	if(Order == "pre-order"){
		dispPreOrd(root);
	}else if(Order == "in-order"){
		dispInOrd(root);
	}

}

void BinaryST::dispPreOrd( Node *n )
{

}

void BinaryST::dispInOrd( Node *n )
{
	if(n->leftChild != nullptr){
		dispInOrd(n->leftChild);
	}

	cout << n->key << endl;

	if(n->rightChild != nullptr){
		dispInOrd(n->rightChild);
	}

}

Node* BinaryST::search( int value )
{
	Node *n = searchRecur(root, value);
	if(n == nullptr){
		cout << "Node not found. Returning nullptr" << endl;
	}
	return n;
}

Node* BinaryST::searchRecur( Node *n , int searchKey )
{
	bool check = false;
	if(n == nullptr || n->key == searchKey){
		return n;
	}

	if(n->key < searchKey){
		return searchRecur(n->rightChild, searchKey);
	}

	return searchRecur(n->leftChild, searchKey);
}

Node* BinaryST::findMin()
{
	return getMin( root );
}

Node* BinaryST::getMin( Node *n )
{
	return nullptr;

}


void BinaryST::deleteNode( int value )
{
	
}



