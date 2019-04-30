#include <iostream>
using namespace std;

#include "heaps.hpp"

void dispArr(float arr[], int arrSize){
	for(int i = 0; i < arrSize; i++){
		if(i == 0){
			cout << "{";
		}
		if(i<arrSize-1){
			cout << arr[i] << ", ";
		}else{
			cout << arr[i] << "}" << endl;
		}
	}
}


int main(){

	//test case 1
	int arr0Size = 5;

	Heap h0(arr0Size);

	float arr0[] = {1.2, 10.5, 5, 15, 20.7};

	cout << "Orginal Array:" << endl;
	dispArr(arr0, arr0Size);

	cout << endl;

	h0.heapSort(arr0, arr0Size);

	cout << "Sorted Array using HeapSort funtion:" << endl;
	dispArr(arr0, arr0Size);

	cout << endl << endl;


	//test case 2

	int arr1Size = 1;
	Heap h1(arr1Size);

	float arr1[] = {5};

	cout << "Orginal Array:" << endl;
	dispArr(arr1, arr1Size);

	cout << endl;

	h1.heapSort(arr1, arr1Size);

	cout << "Sorted Array using HeapSort funtion:" << endl;
	dispArr(arr1, arr1Size);

	cout << endl << endl;


	//test case 3

	int arr2Size = 3;
	Heap h2(arr2Size);

	float arr2[] = {30, 8.2, 34};

	cout << "Orginal Array:" << endl;
	dispArr(arr2, arr2Size);

	cout << endl;

	h2.heapSort(arr2, arr2Size);

	cout << "Sorted Array using HeapSort funtion:" << endl;
	dispArr(arr2, arr2Size);

	cout << endl <<endl;



	//test case 4 (My custom case)

	int arr3Size = 15;
	Heap h3(arr3Size);

	float arr3[] = {55.45, 23.56, 4.6, 1.1, .101, .01, 99.24, 33.33, 23.4, 7.073, 44.445, 78.5, 2.2, 5.7, 3.5};

	cout << "Orginal Array:" << endl;
	dispArr(arr3, arr3Size);

	cout << endl;

	h3.heapSort(arr3, arr3Size);

	cout << "Sorted Array using HeapSort funtion:" << endl;
	dispArr(arr3, arr3Size);

	return 0;
}