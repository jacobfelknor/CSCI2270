#include <iostream>
using namespace std;

int f(int n){

	int result = 0;
	if(n <= 0){return 0;}
	if(n == 1){return 1;}

	result = f(n-1) + f(n-3);
	return result;

}

int main(){

	cout << f(4) << endl;

	return 0;

}