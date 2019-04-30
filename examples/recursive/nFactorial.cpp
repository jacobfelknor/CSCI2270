#include <iostream>
#include <string>
using namespace std;

long long int f(long long int n);

int main(){
	string choice = "0";
	cout << "Factorial Calculator" << endl;

	while(stoi(choice) != -1){
		cout << "Enter an integer or '-1' to exit: ";
		cin >> choice;
		if(stoi(choice) >= 0 && stoi(choice) <= 20){
			cout << choice << "! = " << f(stoi(choice)) << endl;
		}else if(stoi(choice) < -1){
			cout << "Factorial fails on a negative number. Try Again." << endl;
		}else if(stoi(choice) > 20){
			cout << "Error: overflow. Please input a smaller number." << endl;
		}
	}


	return 0;
}


long long int f(long long int n){
	if(n <= 1){
		return 1;
	}else{
		return n*f(n-1);
	}
}