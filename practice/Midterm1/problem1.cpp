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
			tail -> next = temp; //old tail
			tail = temp;		// new tail
			tail -> next = nullptr; //set new tail equal to null
		}
	}


	void displayList(){
		Node *current = head;
		cout << "Display entire linked list: " << endl;

		while(current != nullptr){
			cout << current -> key << " ";
			current = current -> next;
		}
		cout << endl;
	}

	bool lengthIsEven(){
		int count = 0;
		Node *current = head;
		while(current != nullptr){
			current = current -> next;
			count++;
		}

		if(count%2 == 0){
			return true;
		}else{
			return false;
		}
	}
};

int main(){

	SLL list1;
	SLL list2;
	SLL list3;

	for(int i = 0; i < 10; i++){
		list1.appendNode(i+1);
	}

	cout << endl << endl;

	cout << "List 1: "; 
	list1.displayList();
	cout << "Is Even: ";
	if(list1.lengthIsEven()){
		cout << "True" << endl;
	}else{
		cout << "False" << endl;
	}

	cout << endl << endl;



	for(int i = 0; i < 7; i++){
		list2.appendNode(i+1);
	}

	cout << "List 2: "; 
	list2.displayList();
	cout << "Is Even: ";
	if(list2.lengthIsEven()){
		cout << "True" << endl;
	}else{
		cout << "False" << endl;
	}

	cout << endl << endl;


	//test empty list case
	cout << "List 3(NOTE: 0 is being considered even): "; 
	list3.displayList();
	cout << "Is Even: ";
	if(list3.lengthIsEven()){
		cout << "True" << endl;
	}else{
		cout << "False" << endl;
	}

	cout << endl << endl;

	

	return 0;
}