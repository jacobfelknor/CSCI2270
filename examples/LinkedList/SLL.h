// SLL.h - interface file (header file)
#ifndef SLL_H
#define SLL_H

struct Node{
	string key;
	Node *next;
};

class SLL{
private:
	Node *head, *tail;

public:
	SLL(); // constructor declaration

	~SLL();

	Node* search(string sKey);
	// Precodndition: sKey parameter is a string type

	// Postcondition:  if found, returns a pointer to the node containing sKey value.
	// If not found, returns a null pointer.

	void appendNode(string newItem);
	// Precondition: newItem is a valid string.

	// Postcondition: a new node is created. The new node is appended to the end
	// of the existing list. If the list is empty prior to call, new node becomes
	// the head.

	void insert(string afterMe, string newValue);
	// Precondition: afterMe is a valid key value of a node in the linked list.
	// newValue is a valid string.

	// Postcondition: a new node is created and newValue is stored as its key.
	// The new node is added after node containing afterMe.

	void displayList();
	// Precondition: the head node is defined.

	// Post condition: display the key values of the entire list, starting with 
	// first node and ending with last node.

	void deleteNode(string sKey);
	// Precondition: head and tail pointers are set.

	// Post condition: node where with a matching key value is deleted. 

};





#endif