#include <iostream>
using namespace std;

struct Node{
	int key;
	Node *next;	
};

class SLL{
private:
	Node *head, *tail;

public:
	SLL(){
		head = nullptr;
		tail = nullptr;
	}

	void appendNode(int newItem){
		if(head == nullptr){
			head = new Node;
			head -> key = newItem;
			head -> next = nullptr;
			tail = head;
		}else{
			Node *temp = new Node;
			temp -> key = newItem;
			tail -> next = temp; 
			tail = temp;		
			tail -> next = nullptr; 
		}
	}


	void displayList(){
		Node *current = head;
		cout << "Current List: " << endl;

		while(current != nullptr){
			cout << current -> key << " -> ";
			current = current -> next;
		}
		cout << "NULL" << endl;
	}


	int sumEvens(){
		Node *current = head;
		int sum = 0;

		while(current != nullptr){
			if((current->key)%2 == 0){
				sum = sum + current->key;
			}
			current = current -> next;
		}	
		return sum;
	}


};


int main(){
	//first test case

	SLL l1;
	l1.appendNode(7);
	l1.appendNode(4);
	l1.appendNode(6);
	l1.appendNode(2);
	l1.displayList();
	cout << "Sum of evens: " << l1.sumEvens() << endl << endl;


	//second test case
	SLL l2;
	l2.appendNode(3);
	l2.appendNode(9);
	l2.appendNode(2);
	l2.displayList();
	cout << "Sum of evens: " << l2.sumEvens() << endl << endl;

	//third test case
	SLL l3;
	l3.displayList();
	cout << "Sum of evens: " << l3.sumEvens() << endl << endl;

	//fourth test case
	SLL l4;
	l4.appendNode(7);
	l4.appendNode(3);
	l4.appendNode(1);
	l4.appendNode(99);
	l4.appendNode(101);
	l4.displayList();
	cout << "Sum of evens: " << l4.sumEvens() << endl << endl;


	return 0;
}