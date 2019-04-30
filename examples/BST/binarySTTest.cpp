#include <iostream>
using namespace std;

#include "binaryST.h"

int main(){
	BinaryST bst0;

	/*bst0.insert( 9 );
	bst0.insert( 10 );
	bst0.insert( 2 );
	bst0.insert( 10 );
	bst0.insert( 7 );
	bst0.insert( 0 );*/

/*  
        9
       /  \ 
      2   10
     / \    \
    0   7   10
*/


	bst0.insert(19);
	bst0.insert(21);
	bst0.insert(17);
	bst0.insert(14);
	bst0.insert(15);
	bst0.insert(7);
	bst0.insert(12);
	

	cout << "display post-order: " << endl;
	bst0.disp("post-order");
	
	Node *sNode = bst0.search(7);
	if(sNode != nullptr){
		cout << "skey: " << sNode->key << endl;	
	}

	cout << endl << "Root: " << bst0.getRoot()->key << endl;

	int deleteTest = bst0.getRoot()->key;
	bst0.deleteNode(deleteTest);
	cout << "Deleting " << deleteTest << "..." << endl;
	bst0.disp("in-order");
	

	return 0;
}


