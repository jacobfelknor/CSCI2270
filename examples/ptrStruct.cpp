#include <iostream>
using namespace std;

struct Distance{
	int feet;
	int inch;
};

int main(){

	Distance d;
	//Declare a pointer to Distance variable
	Distance *ptr;
	d.feet = 8;
	d.inch = 6;

	//store the address of d in p
	ptr = &d;
	// -> is the access operator when using pointers with structs
	cout << "Distance=" << ptr -> feet << "ft" << ptr -> inch << "inches" << endl;




	return 0;
}