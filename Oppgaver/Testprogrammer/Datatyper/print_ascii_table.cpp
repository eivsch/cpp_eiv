#include <iostream>

using namespace std;

void print_ascii(){
	for(int i=0;i<256;i++){
		if(i%8==0) cout << "\n";
		char c = i;
		cout << i << ": '" << c << "'  ";
	}
}

int main(){
	print_ascii();
}