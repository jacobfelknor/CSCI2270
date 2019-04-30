#include <iostream>
using namespace std;

#include "heaps.hpp"


int main(){

	Heap h0(5);

	cout << "empty: " << h0.isEmpty() << endl;
	cout << "full: " << h0.isFull()  << endl;

	h0.addToHeap(5);
	h0.addToHeap(52);
	h0.addToHeap(23);

	cout << "empty: " << h0.isEmpty() << endl;
	cout << "full: " << h0.isFull()  << endl;
	h0.addToHeap(33);
	h0.addToHeap(93);

	cout << "empty: " << h0.isEmpty() << endl;
	cout << "full: " << h0.isFull()  << endl;


	h0.printHeap();



	return 0;
}