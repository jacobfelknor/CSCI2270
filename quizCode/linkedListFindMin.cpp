#include <iostream>
#include <string>
using namespace std;

struct node{
	int key;
	node *next;
};

int LinkedListFindMinimum(node *head);

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

	/*node *tmp;
	tmp = head;
	while(tmp != nullptr){
		cout << tmp->key << endl;
		tmp = tmp->next;
	}*/

	cout << LinkedListFindMinimum(head) << endl;

	return 0;
}

int LinkedListFindMinimum(node *head){
	int minVal;
	node *temp;
	temp = head;
	minVal = head->key;
	while(temp != nullptr){
		if((temp->key) < minVal){
			minVal = temp->key;
		}
		temp = temp->next;
	}

	return minVal;
}