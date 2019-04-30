#include <iostream>
using namespace std;

#include "hash.hpp"

bool isSubset(int arr1[], int size1, int arr2[], int size2);


int main(){

	int arr1[] = {1,2,3,4,5};
	int size1 = 5;
	int arr2[] = {2,3,1,6};
	int size2 = 4;

	cout << isSubset(arr1, size1, arr2, size2) << endl;

	return 0;
}

bool isSubset(int arr1[], int size1, int arr2[], int size2){
	HashTable h0(size1);

	for(int i = 0; i < size1; i++){
		h0.insertItem(arr1[i]);
	}


	for(int i = 0; i < size2; i++){
		if(!h0.searchItem(arr2[i])){
			return false;
		}
	}


	return true;
}