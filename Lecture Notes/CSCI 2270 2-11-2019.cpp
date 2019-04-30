CSCI 2270 Lecture Notes
2/11/2019

Midterm next friday feb 22, 5-7 pm 
Assignment 4 next sunday, Feb 17
Quiz 4 due tonight


Circular Array Queues
	allow for both the head and tail to shift when enqueueing and dequeueing
	check example folder for basic circular queue class 


Binary Trees
	- Properties
		- Each node has a parent
		- Topmost node is called the root
		- roots parent is NULL
		- each node has a key that identifies identifies it 
		- each node has exactly two children
		- if one of the children is non-existant
				- the child is NULL
		- if both children are NULL
				- the node is called a leaf
		- self-similarity
				- a tree is composed of smaller sub-trees
				- can break down trees into saller trees
		- information in each node
				- pointer to parent
				- key
				- pointer to left child
				- pointer to right child


Binary Search Tree 
	BST - special case of binary tree
		- great for being searched
		- simple rules
			- the left child always has smaller key value than the right child

