#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  while(1) {
    if(N==1)break;
    if(N%2==0)N /= 2;
    else {
      N *=3;
      N += 1;
    }
    cout << N << endl;
  }

  cout << N << endl;
  return 0;
}