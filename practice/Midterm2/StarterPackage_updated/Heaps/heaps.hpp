/*

DISCLAIMER: This is a standard heap implementation we recommend everyone to at least have these functions implemented properly.

For the exams the variable type might change form int to char / any other custom type.
You will also have extra functions which will be the main exam problem which will be added to the hpp file and it will be given to you during your exam

*/


#ifndef HEAP_HPP
#define HEAP_HPP

class Heap
{
	public:

	/*
	class constructor
	Purpose: perform all operations necessary to instantiate a class
	object
	Parameter headSize: Maximum size of the heap
	return: none
	*/
	Heap(int heapSize);
	/*
	class destructor
	Purpose: free all resources that the object has acquired
	Parameters: none
	return: none
	*/
	~Heap();
	
	/*
	Method Name: printHeap
	Purpose: Print the heap array as it is.
	returns void
	*/
	void printHeap();

	/*
	Method Name: addToHeap
	Purpose: Add a new value to the heap and make sure the heap property is maintained
	returns void
	*/
	void addToHeap (int value);
	/*
	Method Name: removeFromHeap
	Purpose: remove the value at the front of the heap, 
	call other method(s) as required to maintain heap
	Parameters: none
	return: The first value of print
	*/
	int removeFromHeap();
	/*
	Method Name: peekValue
	Purpose: return the root of the heap
	Parameters: none
	return: the first element of heap
	*/
	int peekValue(){ return heap[1];}
	/*
	Method Name: isFull
	Purpose: indicate if the heap is full
	Parameters: none
	return: true if queue is full, false otherwise
	*/
	bool isFull();
	/*
	Method Name: isEmpty
	Purpose: indicate if the heap is empty
	Parameters: none
	return: true if queue is empty, false otherwise
	*/
	bool isEmpty();

	private:

	/*
	Method Name: parent
	Purpose: return the parent for the nodeIndex
	Parameter nodeIndex - index of node
	return: int
	*/
	int parent(int nodeIndex){ return (nodeIndex-1)/2;}
	
	/*
	Method Name: leftChild
	Purpose: return the leftChild for the nodeIndex
	Parameter nodeIndex - index of node
	return: int
	*/
	int leftChild(int nodeIndex){ return (2*nodeIndex+1);}
	
	/*
	Method Name: rightChild
	Purpose: return the rightChild for the nodeIndex
	Parameter nodeIndex - index of node
	return: int
	*/
	int rightChild(int nodeIndex){ return (2*nodeIndex+2);}
	
	/*
	Method Name: repairUpward
	Purpose: maintain heap properties by swapping node with parent if necessary
	Parameter nodeIndex - index of node that may violate heap properties
	return: void
	*/
	void repairUpward(int nodeIndex);
	/*
	Method Name: repairDownward
	Purpose: maintain heap properties by swapping node with child if necessary
	Parameter: nodeIndex - index of node that may violate heap properties
	return: void
	*/
	void repairDownward(int nodeIndex);
	void swap(int &x, int&y);

	int* heap; //pointer to the array 
	int currentSize; //current number of students in heap
	int heapSize; //maximum capacity of the heap
};
#endif