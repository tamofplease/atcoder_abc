#include <iostream>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  string s;cin >> s;
  int len = s.length();
  int mi = 1000;
  rep(i,len-2){
    int a = s[i]-'0';int b = s[i+1]-'0';
    int c = s[i+2]-'0';
    int tmp  = a*100+b*10+c;
    mi = min(abs(753-tmp), mi);

  }

  cout << mi << endl;
  return 0;
}