#include <iostream>
using namespace std;

void printArr(int a*);

int main(){

	int a[] = {1, 3, 5, 7};
	
	printArr(a);

	return 0;
}

void printArr(int a*){
	for(int i = 0; i < 4; i++)
		cout << a[i] << endl;
}