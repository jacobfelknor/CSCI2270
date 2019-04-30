#include <iostream>
using namespace std;

int main(){
	int a = 10;
	// ∗ here denote p is pointer variable  
	int *p = &a;

	cout << a << endl;
	cout << p << endl;

	//* is used to dereference p
	cout << *p << endl;

	return 0;
}