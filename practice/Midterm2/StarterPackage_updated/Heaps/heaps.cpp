#include <iostream>
using namespace std;

#include "heaps.hpp"

Heap::Heap(int heapSize){
	currentSize = 0;
	this->heapSize = heapSize;
	heap = new int[heapSize];
}

Heap::~Heap(){
	delete [] heap;
}

void Heap::printHeap() {
    cout << "The heap array is currently {";
    for (int i = 0; i < currentSize; i++) 
    {
        cout << heap[i];
        if (i < currentSize-1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}


void Heap::addToHeap(int k)  //insert function
{
   if(currentSize == heapSize){
        cout << "at capacity, cannot insert key" << endl;

   }else{
        currentSize++;
        int i = currentSize -1;
        heap[i] = k;

    // Fix the min heap property if it is violated
        while(i!=0 && heap[parent(i)] > heap[i]){
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }


   }
}


int Heap::removeFromHeap() //extractMin funciton
{
    if(currentSize <= 0)
        return -1;
    if(currentSize == 1){
        currentSize--;
        return heap[0];
    }

    int poppedVal = heap[0];

    // minHeapify stuff here
    heap[0] = heap[currentSize-1];
    currentSize--;
    repairDownward(0);



    return poppedVal;
    
}



void Heap::repairDownward(int i)
{
    int left = leftChild(i);
    int right = rightChild(i);
    int smallest = i;

    if(left < currentSize && heap[left] < heap[i]){
        smallest = left;
    }
    if(right < currentSize && heap[right] < heap[smallest]){
        smallest = right;
    }


    if(smallest != i){
        swap(heap[i], heap[smallest]);
        repairDownward(smallest);
    }
}

void Heap::swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void Heap::repairUpward(int nodeIndex){
	int i = nodeIndex;
	while(i!=0 && heap[parent(i)] > heap[i]){
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
    }
}


bool Heap::isFull(){
	if(currentSize == heapSize)
		return true;

	return false;
}

bool Heap::isEmpty(){
	if(currentSize == 0)
		return true;

	return false;
}