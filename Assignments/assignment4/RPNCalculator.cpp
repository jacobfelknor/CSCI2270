#include <iostream>
#include "RPNCalculator.hpp"

using namespace std;

RPNCalculator::RPNCalculator(){
	stackHead = nullptr;
}

RPNCalculator::~RPNCalculator(){
	while(!isEmpty()){
		pop();
	}

	stackHead = nullptr;

}

bool RPNCalculator::isEmpty(){
	if(stackHead == nullptr){
		return true;
	}else{
		return false;
	}
}


void RPNCalculator::push(float num){
	Operand *temp = new Operand;
	if(isEmpty()){
		stackHead = temp;
		stackHead->number = num;
		stackHead->next = nullptr;
		temp = nullptr;
	}else{
		temp->number = num;
		temp->next = stackHead;
		stackHead = temp;
		temp = nullptr;
	}
}

void RPNCalculator::pop(){
	if(isEmpty()){
		cout << "Stack Empty, cannot pop an item." << endl;
	}else{
		Operand *temp = new Operand;
		temp = stackHead;
		stackHead = stackHead->next;
		delete temp;
		temp = nullptr;
	}
}

Operand* RPNCalculator::peek(){
	if(isEmpty()){
		cout << "Stack empty, cannot peek." << endl;
		return nullptr;
	}else{
		/*Operand *temp = stackHead;
		while(temp!=nullptr){
			cout << temp->number << endl;
			temp = temp->next;
		}*/

		return stackHead;
	}
	
}


bool RPNCalculator::compute(std::string symbol){
	if((symbol != "+") && (symbol != "*")){
		cout << "err: invalid operation" << endl;
		return false;
	}


	float num1, num2, ans;
	Operand *ptr1, *ptr2;

	if(isEmpty()){
		cout << "err: not enough operands" << endl;
		return false;
	}
	ptr1 = peek();
	num1 = ptr1->number;
	pop();

	if(isEmpty()){
		cout << "err: not enough operands" << endl;
		push(num1);
		return false;
	}
	ptr2 = peek();
	num2 = ptr2->number;
	pop();

	if(symbol == "+"){
		ans = num1 + num2;
	}else{
		ans = num1 * num2;
	}

	push(ans);

	/*Operand *temp = stackHead;
	while(temp!=nullptr){
		cout << temp->number << endl;
		temp = temp->next;
	}*/
}