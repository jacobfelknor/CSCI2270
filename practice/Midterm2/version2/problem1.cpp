#include <iostream>
using namespace std;

#include "BST.hpp"


int main(){

	BST t0(20);

	t0.addNode(15);
	t0.addNode(30);
	t0.addNode(40);
	t0.addNode(3);
	t0.addNode(18);
	t0.addNode(7);
	t0.addNode(6);
	t0.addNode(5);
	t0.addNode(4);


	//t0.printRoof();

	BST t1(18);

	t1.addNode(30);
	t1.addNode(20);
	t1.addNode(40);

	//t1.printRoof();


	BST t2(30);

	t2.addNode(20);

	//t2.printRoof();


	BST t3(50);

	t3.addNode(49);
	t3.addNode(59);
	t3.addNode(30);
	t3.addNode(23);
	t3.addNode(37);
	t3.addNode(61);
	t3.addNode(52);
	t3.addNode(53);
	t3.addNode(60);

	t3.printRoof();


	return 0;
}