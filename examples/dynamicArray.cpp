#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){

	int n;
	int *ptr;
	int *temp;
	cout << "Enter an starting length:" << endl;
	cin >> n;
	ptr = new int[n];
	for(int i = 0; i < n; i++){
		cin >> ptr[i];
	}

	cout << "before: " << endl;
	for(int i = 0; i < n; i++){
		cout << ptr[i] << " " ;
	}
	
	temp = new int[2*n];

	for(int i = 0; i < n; i++){
		temp[i] = ptr[i];
	}

	delete [] ptr; //deallocate entire array

	ptr = temp;

	temp = NULL;

	cout << "after: " << endl;
	for(int i = 0; i < 2*n; i++){
		cout << ptr[i] << " ";
	}

	delete [] ptr;

	
	return 0;
}