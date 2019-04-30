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
		//cout << "Current List: " << endl;

		while(current != nullptr){
			cout << current -> key << " -> ";
			current = current -> next;
		}
		cout << "NULL" << endl;
	}

	void deleteNode(int sKey){
		Node *tmp;
		if(head->key == sKey){
			//head case
			tmp = head;
			head = head->next;
			delete tmp;
			tmp = nullptr;
		}else{
			bool found = false;
			Node *last = head;
			tmp = head->next;
			while(!found && tmp!=nullptr){
				if(tmp->key == sKey){
					found = true;
				}else{
					last = tmp;
					tmp = tmp->next;
				}
			}

			if(found){
				if(tmp->next == nullptr){
					//the tail case
					last->next = nullptr;
					tail = last;
				}else{
					//middle case
					last->next = tmp->next;
				}
				delete tmp;
				tmp = nullptr;
				last = nullptr;
			}
		}
	}


	Node *splitEvenOdd(){
		SLL newList;
		Node *current = head;
		Node *temp;

		while(current != nullptr){
			if((current->key)%2 == 0){
				newList.appendNode(current->key);
				temp = current->next;	//keep track of where current should be after deletion
				deleteNode(current->key);
				current = temp;			// iterate current after deletion
				temp = nullptr;
			}else{
				current = current -> next;
			}
		}

		return newList.getHead();
	}


	Node *getHead(){
		return head;
	}



};


void displayList(Node *head);


int main(){
	//setting up original list
	SLL l1;	
	for(int i = 0; i < 17; i++){
		l1.appendNode(i);
	}
	cout << "Original List:" << endl;
	displayList(l1.getHead());
	cout << endl;

	//splitting happens here
	cout << "Even List: ";
	Node *newList = l1.splitEvenOdd();
	displayList(newList);

	cout << "Odd List: ";
	displayList(l1.getHead());




	return 0;
}


void displayList(Node *head){
		Node *current = head;
		//cout << "Current List: " << endl;

		while(current != nullptr){
			cout << current -> key << " -> ";
			current = current -> next;
		}
		cout << "NULL" << endl;
	}