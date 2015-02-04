#include <vector>
#include <iostream>

using namespace std;

int main(){
	vector<int> v(5);
	for(int i=0;i<v.capacity();i++) v[i] = i;

    v.reserve(10);
	v[10] = 9;

	for(int i=0;i<v.capacity();i++) cout << v[i] << endl;
}