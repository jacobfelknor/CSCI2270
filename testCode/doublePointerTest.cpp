#include <iostream>
using namespace std;

void printArray(int **array, int array_size){
	for(int i = 0; i < array_size; i++){
		cout << (*array)[i] << endl;
	}
}

int main(int argc, char *argv[]){
	int *a = new int[5];
	int array_length = 5;
	for(int i = 0; i < array_length; i++){
		a[i] = i;
	}
	printArray(&a, array_length);
	return 0;
}