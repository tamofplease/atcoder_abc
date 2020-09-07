#include <iostream>
 
using namespace std;
 
int main() {
  int N,K;
  cin >> N >> K;
  if(N>=10)cout << K << endl;
  else cout << K+100*(10-N)) << endl;
  return 0;
}