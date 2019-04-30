#include <iostream>
#include <vector>
using namespace std;

int main(){
	//declare vector of ints
	//no need to specify size (you can if you want)
	vector<int> v0;

	cout << "v0 length " << v0.size() << endl;

	v0 = {2,2,7,0};

	cout << "v0 length " << v0.size() << endl;

	//with vectors we can append at the end
	//the container will automatically accomidate teh size
	v0.push_back(9);
	cout << "v0 length " << v0.size() << endl;

	//can reduce the size of vector 
	v0.pop_back();
	cout << "v0 length " << v0.size() << endl;

	//to initialize size, just pass the size to constructor
	vector<int> v1(7);
	cout << "v1 length " << v1.size() << endl;
	//can also resize
	v1.resize(20);
	//v1.push_back(1);
	cout << "v1 length " << v1.size() << endl;


}
