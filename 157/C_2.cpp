#include <algorithm>
#include <iostream>

using namespace std;

const int MAXM=6;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)

int N,M;
int s[MAXM],c[MAXM];

bool ok(int x) {
  int bin[MAXM];
  int i = N;
  while(1) {
    bin[i] = x%10; 
    i--;
    x /= 10;
    if(i==0)break;
  }
  bool flag = true;
  rep(i,M) {
    if(bin[s[i]] != c[i])flag = false;
  }

  return flag;
}

int main() {
  

  cin >> N >> M;
  rep(i,M) cin >> s[i] >> c[i];


  int max_digit = 1;
  int min_digit = 1;
  if(N == 1) {
    max_digit = 10;
    min_digit = 0;
  }else{
    rep(i,N){
      max_digit *= 10;
      min_digit *= 10;
    }
    min_digit /= 10;
  }
  int k;
  for(k=min_digit;k<max_digit;k++) {
    if(ok(k)) {
      cout << k << endl;
      return 0;
    }
  }

  cout << -1 << endl;



  return 0;
}