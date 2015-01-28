#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;
 int main(){
 	int n;
 	cin >> n;

 	int array[n];
 	vector<int> v(n);
 	map<string,int> m;

 	srand(time(NULL));

 	clock_t begin_time = clock();
  	for(int i =0;i<n;i++) array[i] = rand()%100;
  	cout << float(clock()-begin_time) / CLOCKS_PER_SEC << endl;

  	begin_time = clock();
  	for(int i=0;i<n;i++) v[i]=rand()%100;
  	cout << float(clock()-begin_time) / CLOCKS_PER_SEC << endl;	


 	int i = 0;
 	begin_time = clock();
 	while(i<n){
 		ostringstream oss;
 		oss << i;
 		m["s" + oss.str()] = rand()%100;
 		i++;
 	}
 	cout << float(clock()-begin_time) / CLOCKS_PER_SEC << endl;
 	/*
 	for(auto& kv : m){
 		cout << kv.first << " has value " << kv.second << endl;
 	}*/
 }