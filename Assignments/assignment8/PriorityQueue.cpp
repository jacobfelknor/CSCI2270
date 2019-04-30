#include <iostream>
#include <string>
using namespace std;

#include "PriorityQueue.hpp"




void printHeap(GroupNode heap[], int &currentSize) {
    //cout << "The heap array is currently {";
    for (int i = 0; i < currentSize; i++){ 
    	cout << "Group Name: " << heap[i].groupName << endl;
    	cout << "groupsize: " << heap[i].groupSize << endl;
    	cout << "cookingTime: " << heap[i].cookingTime << endl << endl;
    }
       
}





void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int parent(int i) { return (i-1)/2; }
int left(int i) { return (2*i+1); }
int right(int i) { return (2*i + 2); }

PriorityQueue::PriorityQueue(int queueSize){
	maxQueueSize = queueSize;
	currentQueueSize = 0;
	priorityQueue = new GroupNode [queueSize];
}

PriorityQueue::~PriorityQueue(){
	delete [] priorityQueue;
}

void PriorityQueue::enqueue(string _groupName, int _groupSize, int _cookingTime){
	if(!isFull()){
		//cout << "heap is not full" << endl;
		int i = currentQueueSize++;
		priorityQueue[i].groupName = _groupName;
		priorityQueue[i].groupSize = _groupSize;
		priorityQueue[i].cookingTime = _cookingTime;

		repairUpward(i);
		 
	}else{
		cout << "Heap full, cannot enqueue" << endl;
	}
		
}	

void PriorityQueue::dequeue(){
	if(isEmpty()){
		cout << "Heap empty, cannot dequeue" << endl;
	}else{
		priorityQueue[0] = priorityQueue[currentQueueSize -1];
		currentQueueSize--;
		repairDownward(0);
	}
}

GroupNode PriorityQueue::peek(){
	//printHeap(priorityQueue, currentQueueSize);
	if(isEmpty()){
		cout << "Heap empty, nothing to peek" << endl;
	}
	
	return priorityQueue[0];
}	

bool PriorityQueue::isFull(){
	if(currentQueueSize == maxQueueSize){
		return true;
	}else{
		return false;
	}
}

bool PriorityQueue::isEmpty(){
	if(currentQueueSize <= 0){
		return true;
	}else{
		return false;
	}
}

void PriorityQueue::repairUpward(int nodeIndex){
	int i = nodeIndex;
	while(i != 0 && priorityQueue[parent(i)].groupSize >= priorityQueue[i].groupSize){
			if(priorityQueue[parent(i)].groupSize > priorityQueue[i].groupSize){
				swap(priorityQueue[i], priorityQueue[parent(i)]);
			}else{
				if(priorityQueue[parent(i)].cookingTime > priorityQueue[i].cookingTime){
					swap(priorityQueue[i], priorityQueue[parent(i)]);
				}
			}

			i = parent(i);
		}
}

void PriorityQueue::repairDownward(int nodeIndex){
	int i = nodeIndex;

	int leftChild = left(i);
	int rightChild = right(i);
	int priority = i;

	if(leftChild < currentQueueSize && priorityQueue[leftChild].groupSize <= priorityQueue[i].groupSize){
		if(priorityQueue[leftChild].groupSize < priorityQueue[i].groupSize){
			priority = leftChild;
		}else if(priorityQueue[leftChild].cookingTime < priorityQueue[i].cookingTime){
			priority = leftChild;
		}
	}

	if(rightChild < currentQueueSize && priorityQueue[rightChild].groupSize <= priorityQueue[priority].groupSize){
		if(priorityQueue[rightChild].groupSize < priorityQueue[priority].groupSize){
			priority = rightChild;
		}else if(priorityQueue[rightChild].cookingTime < priorityQueue[priority].cookingTime){
			priority = rightChild;
		}
	}

	if(priority != i){
		swap(priorityQueue[i], priorityQueue[priority]);
		repairDownward(priority);
	}


}