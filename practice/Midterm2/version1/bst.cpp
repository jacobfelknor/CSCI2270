#include <iostream>
using namespace std;

#include "bst.h"

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
	}else if(Order == "post-order"){
		dispPostOrd(root);
	}else{
		cout << "display method not supported/recognized" << endl;
	}

}

void BinaryST::dispPreOrd( Node *n )
{
	cout << n->key << endl;


	if(n->leftChild != nullptr){
		dispPreOrd(n->leftChild);
	}

	if(n->rightChild != nullptr){
		dispPreOrd(n->rightChild);
	}
}

void BinaryST::dispPostOrd( Node *n )
{

	if(n->leftChild != nullptr){
		dispPostOrd(n->leftChild);
	}

	if(n->rightChild != nullptr){
		dispPostOrd(n->rightChild);
	}

	cout << n->key << endl;

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
	return searchRecur(root, value);
}

Node* BinaryST::searchRecur( Node *n , int searchKey )
{
	
	if(n != nullptr){
		//cout << "node visited: " << n->key << endl;
		if(n->key == searchKey){
			return n;
		}else if(n->key > searchKey){
			return searchRecur(n->leftChild, searchKey);
		}else{
			return searchRecur(n->rightChild, searchKey);
		}
	}else{
		cout << searchKey << " not found" << endl;
		return nullptr;
	}
	
}

Node* BinaryST::findMin()
{
	return getMin( root );
}

Node* BinaryST::getMin( Node *n )
{
	while(n->leftChild != nullptr){
		n = n->leftChild;
	}

	return n;

}


void BinaryST::deleteNode( int value )
{
	Node *n = search(value);

	//Non-root case
	if(n != root){
		// I) the leaf case (n is a leaf node)
		if(n->leftChild == nullptr && n->rightChild == nullptr){
			// Need to go up to the parent node and update the correct 
			//child pointer
			//check n's relationship to its parents
			//is n the left child
			if(n==n->parent->leftChild){
				n->parent->leftChild = nullptr;
			}
			//otherwise, n must be the right child
			else{
				n->parent->rightChild = nullptr;
			}
		}
		// II) the two children case
		else if(n->leftChild != nullptr && n->rightChild != nullptr){
			//find the min of the right sub tree to replace the deleted
			//node
			Node *min = getMin(n->rightChild);
			//if min is the right child of n
			if(min == n->rightChild){
				//make parent point to the min
				//check if node is left child
				if(n == n->parent->leftChild){
					n->parent->leftChild = min;
				}
				//otherwise it is a right child
				else{
					n->parent->rightChild = min;
				}

				//make min point to the parent
				min->parent = n->parent;
				//make min point to n's old child
				min->leftChild = n->leftChild;
				//make old LC point to min
				min->leftChild->parent = min;
			}
			//otherwise, min is not the right child of n
			//meaning its somehwere in the right subtree
			else{ 
				//min's old RC takes min's spot
				min->parent->leftChild =  min->rightChild;

				//new node needs to point back up to min's former parent
				if(min->rightChild != nullptr){
					min->rightChild->parent = min->parent;
				}

				//now, insert the actual min into n's old spot
				//check if node is LC
				if(n == n->parent->leftChild){
					n->parent->leftChild = min;
				}//otherwise it is the right child
				else{
					n->parent->rightChild = min;
				}

				min->parent = n->parent;
				min->leftChild = n->leftChild;
				min->leftChild->parent  = min;
				min->rightChild = n->rightChild;
				min->rightChild->parent = min;
			}
		}
		// III) The one child case
		else{
			// 1) the one child is a left child
			if(n->leftChild != nullptr){
				n->leftChild->parent = n->parent;
				//check if node is left child
				if(n == n->parent->leftChild){
					n->parent->leftChild = n->leftChild;
				}else{ // otherwise it is the RC
					n->parent->rightChild = n->leftChild;
				}
			}else{// 2) the one child is the right child
				n->rightChild->parent = n->parent;
				//check if node is left child
				if(n == n->parent->leftChild){
					n->parent->leftChild = n->rightChild;
				}else{ // otherwise it is the RC
					n->parent->rightChild = n->rightChild;
				}
			}


		}
	}else{//Root case

		if(n->rightChild == nullptr && n->leftChild == nullptr){ //root is only node
			root = nullptr;
		}else if(n->rightChild == nullptr && n->leftChild != nullptr){//only left subtree exists
			root = n->leftChild; 
			root->parent = nullptr;
		}else if(n->rightChild != nullptr && n->leftChild == nullptr){//only right subtree exists
			root = n->rightChild;
			root->parent = nullptr;
		}else{	// both right and left subtrees exist


			//find the min of the right sub tree to replace the deleted
			//node
			Node *min = getMin(n->rightChild);
			//if min is the right child of n
			if(min == n->rightChild){
				min->leftChild = n->leftChild;
				min->parent = nullptr;
				root = min;
			}
			//otherwise, min is not the right child of n
			//meaning its somehwere in the right subtree
			else{ 
				//min's old RC takes min's spot
				min->parent->leftChild =  min->rightChild;

				//new node needs to point back up to min's former parent
				if(min->rightChild != nullptr){
					min->rightChild->parent = min->parent;
				}

				min->leftChild = n->leftChild;
				min->rightChild = n->rightChild;
				n->rightChild->parent = min;
				min->parent = nullptr;
				root = min;
			}


		}


	} 
	
	delete n;
}


int getMaxDepthHelper(Node *n, int &currentDepth,int &depth){

	if(n->leftChild != nullptr){
		currentDepth++;
		getMaxDepthHelper(n->leftChild, currentDepth, depth);
	}

	if(n->rightChild != nullptr){
		currentDepth++;
		getMaxDepthHelper(n->rightChild, currentDepth, depth);
	}

	
	if(currentDepth > depth){
		depth = currentDepth;
	}


	currentDepth--;
}

int BinaryST::getMaxDepth(){
	int currentDepth = 0;
	int depth = 0;
	getMaxDepthHelper(root, currentDepth, depth);
	return depth;
}





