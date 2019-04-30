#include <iostream>
using namespace std;

#include "BST.hpp"


int main(){
	BST tree(5);


	tree.addNode(2); //left child to 5
	tree.addNode(1); //left child to 1
	tree.addNode(4); //right child to 2
	tree.addNode(7); //right child to 5
	tree.addNode(10); //right child of 7
	tree.addNode(8); // left child of 10
	tree.addNode(6); // left child of 7


	tree.printTree();


	cout << endl << endl;

	tree.deleteNode(2);

	tree.printTree();

	return 0;
}