#include "ProducerConsumer.hpp"
#include <iostream>

using namespace std;

string queue[SIZE];
int queueFront;
int queueEnd;
int currentSize = 0;

ProducerConsumer::ProducerConsumer(){
	queueFront = -1;
	queueEnd = -1;
}	


bool ProducerConsumer::isEmpty(){
	if(currentSize == 0){
		return true;
	}
	return false;
}

bool ProducerConsumer::isFull(){
	if(currentSize == SIZE){
		return true;
	}else{
		return false;
	}
	
}

void ProducerConsumer::enqueue(std::string player){
	if(isEmpty()){
		queueFront = 0;
		queueEnd = 0;
		queue[queueFront] = player;
		queueEnd++;
		currentSize++;
	}else if(!isFull()){
		queue[queueEnd] = player;
		if(queueEnd == SIZE - 1){
			queueEnd = 0;
		}else{
			queueEnd++;
		}
		currentSize++;
	}else{
		cout << "Queue full, cannot add new item" << endl;
	}
}

void ProducerConsumer::dequeue(){
	if(!isEmpty()){
		if(queueFront == SIZE - 1){
			queueFront = 0;
		}else{
			queueFront++;
		}
		currentSize--;
		if(currentSize == 0){
			queueFront = -1;
			queueEnd = -1;
		}
	}else{
		cout << "Queue empty, cannot dequeue an item" << endl;
	}
}

int ProducerConsumer::queueSize(){
	if(isEmpty()){
		return 0;
	}else if(isFull()){
		return SIZE;
	}else{
		return currentSize;
	}
}

string ProducerConsumer::peek(){

	if(isEmpty()){
		cout << "Queue empty, cannot peek" << endl;
		return "";
	}else{
		return queue[queueFront];
	}


	/*if(queueEnd != queueFront){
		for(int i = queueFront; i < queueEnd; i++){
			cout << queue[i] << endl;
		}
	}else{
		for(int i = 0; i < SIZE; i++){
			cout << queue[i] << endl;
		}
	}*/
	
}