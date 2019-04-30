#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

struct TreeNode{
		char key;
		TreeNode *left;
		TreeNode *right;
		TreeNode *parent;	
};

struct Node{
		char key;
		Node *next;
};

Node *head = NULL;


void rangeSearchRecu(TreeNode *node, char m, char n){

	if(node->left != nullptr){
		rangeSearchRecu(node->left, m, n);
	}

	//cout << node->key << endl;
	//check if value is within given range
	//if true, append to the linked list
	if(node->key >= m && node->key <= n){
		Node *temp = new Node;
		temp->key = node->key;
		if(head == nullptr){
			head = temp;
			head->next = nullptr;
		}else{
			Node *scan = head;
			while(scan->next != nullptr){
				scan = scan->next;
			}
			scan->next = temp;
			temp->next = nullptr;
		}
	}

	if(node->right != nullptr){
		rangeSearchRecu(node->right, m, n);
	}

}

void RangeSearch(TreeNode *node, char m, char n){

	// **************************
	// STUDENT SOLUTION GOES HERE
	// **************************

	rangeSearchRecu(node, m, n);
	
}


void inOrderTraversal(TreeNode *root){
		if(root){
				inOrderTraversal(root->left);
				cout << root-> key << endl;
				inOrderTraversal(root->right);
		}
}

void printLinkedList(){
	Node* walker = head;
	
	while(walker != NULL){
		char a = (walker->key);
		cout << a << " -> ";
		walker=walker->next;
	}
	cout << "NULL"<<endl;
}

int main() {

	// The tree is built here (provided): 

	TreeNode *root = NULL;
	char a[] = {'g','e','o','a','f','i','b','c','d'};
	int length = 9;

	for(int i=0; i<length; i++) {
		TreeNode *newnode = new TreeNode;
		newnode->key = a[i];
		newnode->left=NULL;
		newnode->right=NULL;	
		newnode->parent = NULL;
		if(root == NULL) {
			root = newnode;
		}
		else {
			TreeNode *temp = root;
			TreeNode *temp2 = NULL;
			while(temp!=NULL) {
				temp2=temp;
				if(temp->key > a[i]) {
					temp = temp->left;
				}
				else {
					temp = temp->right;
				}
		}
		if(a[i]<temp2->key)
		{
			newnode->parent = temp2;
			temp2->left = newnode;
		}
		else
		{
			newnode->parent = temp2;
			temp2->right = newnode;
		}

		}
	}

	//cout<<endl<<"In Order Traversal:"<<endl;
	//inOrderTraversal(root);
	char start_range = 'a';
	char end_range = 'f';

	RangeSearch(root,start_range,end_range);
	
	printLinkedList();
	
	return 0;
}
