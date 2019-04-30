#include <iostream>
using namespace std;

struct node
{
    int key;
    node *next;
};

node *reverse(node *head);

int main(){

	node *head = nullptr, *tail = nullptr;
	
	string sTemp;
	int newItem;

	for(int i = 0; i < 3; i++){
		getline(cin, sTemp);
		newItem = stoi(sTemp);
		if(head == nullptr){
			head = new node;
			head -> key = newItem;
			head -> next = nullptr;
			tail = head;
		}else{
			node *temp = new node;
			temp -> key = newItem;
			tail -> next = temp; //old tail
			tail = temp;		// new tail
			tail -> next = nullptr; //set new tail equal to null
		}

	}

	head = reverse(head);	

	cout << endl;

	node *current = head;
	while(current != nullptr){
		cout << current->key << endl;
		current = current->next;
	}

	return 0;
}



node *reverse(node *head){
	node *prev = nullptr;
	node *current = head;
	node *next = nullptr;
	while(current != nullptr){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;
	return head;
}

