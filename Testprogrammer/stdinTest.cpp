#include <iostream>

using namespace std;

int main() {
	string input_line;
  	/*while(cin) {
    	getline(cin, input_line);
    	cout << input_line << endl;
  	};

  	return 0;*/
  	int count = 0;
  	while(cin){
  		cin >> input_line;
  		count++;
  	}
  	cout << "Number of words: " << count-1 <<endl;
}