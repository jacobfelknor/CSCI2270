#include <iostream>
using namespace std;

#include "BST.hpp"


int main(){

	BST t0;

	t0.addNode(9);
	t0.addNode(7);
	t0.addNode(16);
	t0.addNode(4);
	t0.addNode(8);
	t0.addNode(4);
	t0.addNode(11);

	//t0.printTree();

	cout << "For the tree:" << endl;
	t0.print2DUtil(1);

	cout << "sumRange(8,12) returns " << t0.sumRange(8,12) << endl << endl;


	BST t1;

	t1.addNode(4);
	t1.addNode(2);
	t1.addNode(7);

	cout << "For the tree:" << endl;
	t1.print2DUtil(1);

	cout << "sumRange(8,10) returns " << t1.sumRange(8,10) << endl << endl;


	BST t2;

	cout << "For an empty tree:" << endl;
	t2.print2DUtil(1);

	cout << "sumRange(8,12) returns " << t2.sumRange(8,12) << endl << endl;


	BST t3;

	t3.addNode(34);
	t3.addNode(67);
	t3.addNode(12);
	t3.addNode(7);
	t3.addNode(3);
	t3.addNode(74);
	t3.addNode(45);
	t3.addNode(65);
	t3.addNode(99);

	cout << "For the tree:" << endl;
	t3.print2DUtil(1);

	cout << "sumRange(30,59) returns " << t3.sumRange(30,59) << endl << endl;



	return 0;
}