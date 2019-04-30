#include <iostream>
using namespace std;


int main(){

	/*int a=100, b=200, c=50, *pa=&a, *pb=&b, *pc=&c;
	*pa = *pa + *pb + *pc;
	*pb = 100;
	pb=pa;
	pc=pb;
	
	cout << *pa << "," << *pb << "," << *pc << endl;
	*/
	int m=1, n=2, *p=&m, *q=&n, *r;
	r=p;p=q;q=r;
	cout <<m<<","<<n<<","<<*p<<","<<*q<<endl;

	return 0;
}

