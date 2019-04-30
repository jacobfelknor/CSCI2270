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


	Node *deleteNegatives(){

		Node *current = head;
		Node *temp = nullptr;
		while(current != nullptr){
			if(current->key < 0){
				temp = current->next;
				deleteNode(current->key);
				current = temp;
				temp = nullptr;
			}else{
				current = current->next;
			}
		
		}

		return head;
	}
};

int main(){

	SLL l1;
	
	l1.appendNode(5);
	l1.appendNode(-5);
	l1.appendNode(-15);
	l1.appendNode(53);

	l1.displayList();

	l1.deleteNegatives();

	l1.displayList();

	SLL l2;
	l2.appendNode(-5);
	l2.appendNode(-5);
	l2.appendNode(-15);
	l2.appendNode(-53);

	l2.displayList();

	l2.deleteNegatives();

	l2.displayList();



	return 0;
}