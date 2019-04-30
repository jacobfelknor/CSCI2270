#include <iostream>
using namespace std;

#include "queArrCir.h"

QueArrCir::QueArrCir(){
	head = 0;
	tail = 0;
	queSize = 0; // current size
}

bool QueArrCir::isEmpty(){
	if(queSize == 0){
		return true;
	}else{
		return false;
	}
}

bool QueArrCir::isFull(){
	if(queSize == MAXSIZE){
		return true;
	}else{
		return false;
	}
}


void QueArrCir::enque(string newItem){
	if(!isFull()){
		a[tail] = newItem;
		queSize++;
		if(tail == MAXSIZE - 1){
			tail = 0;
		}else{
			tail++;
		}
	}else{
		cout << "queue is full" << endl;
	}
}

string QueArrCir::deque(){
	string output;
	if(!isEmpty()){
		output = a[head];
		queSize--;
		if(head == MAXSIZE - 1){
			head = 0;
		}else{
			head++;
		}
	}else{
		cout << "Queue is empty. returning empty string" << endl;
		output = "";
	}
}