#include <iostream>
using namespace std;

int main() {
  int N;cin >> N;
  int tmp = 0;
  while(tmp<N) {
    tmp += 1000;
  }
  cout << N - tmp << endl;
}