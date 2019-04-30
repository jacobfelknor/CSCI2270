#include <iostream>
using namespace std;

struct Node{
	int value;
	struct Node *next;
};

int main(){

	Node n1;
	n1.value = 1;
	n1.next = 0;

	Node *n2 = 0;
	n2 = &n1;

	Node *n3 = new Node;
	(*n3).value = 3;
	
	Node *n4 = new Node;
	(*n4).value = 4;
	(*n4).next = &n1;


	Node *n5 = n4;
	n5->next = n2;


	return 0;
}