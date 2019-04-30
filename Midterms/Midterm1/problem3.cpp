#include <iostream>
using namespace std;

struct Node{
	int key;
	Node *next;	
};

class SLL{
private:
	Node *head, *tail;
	int count = 0;

public:
	SLL(){
		head = nullptr;
		tail = nullptr;
	}

	void insertEnd(int newItem){
		if(head == nullptr){
			head = new Node;
			head -> key = newItem;
			head -> next = nullptr;
			tail = head;
			count++;
		}else{
			Node *temp = new Node;
			temp -> key = newItem;
			tail -> next = temp; 
			tail = temp;		
			tail -> next = head; 
			count++;
		}
	}


	void print(){
		Node *current = head;
		//cout << "Current List: " << endl;

		for(int i = 0; i < count; i++){
			cout << current -> key << " -> ";
			current = current -> next;
		}
		cout << "NULL" << endl;
	}

	void shift(int n){
		if(n > count){
			n = n%count;
		}else if( n < 0){
			cout << "Shift cannot be negative. Displying original list" << endl;
		}

		for(int i = 0; i < n; i++){
			head = head->next;
			tail = tail->next;
		}
	}


};


int main(){

	SLL l1;

	for(int i = 0; i < 4; i++){
		l1.insertEnd(i+1);
	}
	cout << "Current List: ";
	l1.print();
	cout << endl;
	int shift = -2;
	l1.shift(shift);
	if(shift > 0){
		cout << "List shifted by " << shift << ":" << endl;
	}
	l1.print();

	return 0;
}