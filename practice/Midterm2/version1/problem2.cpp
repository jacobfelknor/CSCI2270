#include <iostream>
using namespace std;

#include "bst.h"


int main(){
	BinaryST bst0;
	BinaryST bst1;
	BinaryST bst2;

	bst0.insert(20);
	bst0.insert(30);
	bst0.insert(40);
	bst0.insert(15);
	bst0.insert(4);
	bst0.insert(7);
	bst0.insert(18);
	bst0.insert(19);


	bst1.insert(18);
	bst1.insert(30);
	bst1.insert(20);
	bst1.insert(40);

	bst2.insert(30);
	bst2.insert(20);


	cout << bst0.getMaxDepth() << endl;
	cout << bst1.getMaxDepth() << endl;
	cout << bst2.getMaxDepth() << endl;

	return 0;
}