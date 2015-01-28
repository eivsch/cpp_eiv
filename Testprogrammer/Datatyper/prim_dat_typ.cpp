#include <iostream>

using namespace std;

int main(){
	
	long long l{4000000000};
	float f{3.14};  
	int i{f}; 
	char c = i;
	double d;
	cout << "sizeof(f): " << sizeof(f) << "\nsizeof(i) " << sizeof(i) << endl;
	cout << "sizeof(c): " << sizeof(c) << "\nsizeof(d): " << sizeof(d) << endl;

	
	int* iptr; 
	char* cptr;	
	cout << "\nsizeof(iptr): "<< sizeof(iptr) << "\nsizeof(cptr): " << sizeof(cptr) << endl;

	cout << "\nvalue of f: " << f <<endl;
	cout << "value of i: " << i << endl;
	cout << "value of c: " << c << endl;
	cout << "value of d: " << d << endl;

	cout << "\nvalue of iptr: " << iptr << endl;
	cout << "value of cptr: \n" << cptr << endl;
}