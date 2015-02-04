#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

const int INIT_SEQ = 20;
const int MAX_SPINS = 10000000;

int main(){
	
	int nSpins = MAX_SPINS;
	cout << "Enter number of spins: ";
	cin >> nSpins;

	srand(time(NULL));
	int hitsEachColor[2];
	vector<int> v(INIT_SEQ);
	int count=0, rnd, prevRnd, seq = 1;
	rnd = rand()%2;

	while(count<nSpins){
		count++;
		hitsEachColor[rnd]++;
		prevRnd=rnd;
		rnd=rand()%2;
		if(rnd==prevRnd) seq++;
		else{
			if(seq>v.capacity()) v.resize(seq+2);
			v[seq]++;
			seq = 1;
		}
	}
	cout << "RED: " << hitsEachColor[0] << " GREEN: " << hitsEachColor[1] << endl;
	for(int i = 1;i<v.size(); i++){
		cout << "Antall " << i << " på rad: " << v[i] << endl;
	}
}