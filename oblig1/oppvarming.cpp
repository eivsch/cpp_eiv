#include <iostream>
#include <bitset>
#include <string>

using namespace std;

long long msg1{28539401679696455};

int msg2[]{1918986818,1998611822,1684829551,
    544483182,1701538156,1768453152,8563};


int encrypted[]{1498105673, 1227249735, 1498829639,
    1196119078, 1314530904, 1197024843, 5853000};

int main(){

  // Print out the messages in human-readable form!

  // gjør om til char-pointers for å lese binært
  char *decode1 = (char *)&msg1; 
  char *decode2 = (char *)msg2;
  char *decode3 = (char *)encrypted;

  // finner lengden til encrypted[] og offset er -6
  string s=decode3;
  for(int i=0;i<s.length();i++) decode3[i]-=6;                     

  cout << "Message 1: " << decode1 << endl;
  cout << "Message 2: " << decode2 << endl;
  cout << "Decrypted: " << decode3 << endl;
}
