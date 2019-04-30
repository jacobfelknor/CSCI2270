#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void dispArray(int arr[], int length);

int insertIntoSortedArray(int arr[], int numEntries, int newValue);

int main(int argc, char *argv[]){

	int N = 100;
	int arr[N];

	for(int i = 0; i < N; i++){
		arr[i] = 0;
	}

	ifstream inStream;
	inStream.open(argv[1]);
	string tempString;
	int tempInt;
	int numEntries = 0;

	if(!inStream.is_open()){
		cout << "Failed to open the file." << endl;
		exit(0);
	}else{
		while(inStream >> tempString){
			insertIntoSortedArray(arr, numEntries, stoi(tempString));
			dispArray(arr, numEntries + 1);
			numEntries++;
		}	
	}

	return 0;
}


int insertIntoSortedArray(int arr[], int numEntries, int newValue){
	int j = numEntries;

	while((j > 0) && (newValue < arr[j - 1])){
		arr[j] = arr[j - 1];
		j--;
	}
	
	arr[j] = newValue;
	return numEntries + 1;
	

}



void dispArray(int arr[], int length){
	//auxiliary function 
	if(length == 1){
		cout << arr[0];
	}else{
		for(int i = 0; i < (length - 1); i++){
		cout << arr[i] << ",";
		}

		cout << arr[length - 1];
	}

	cout << endl;
}