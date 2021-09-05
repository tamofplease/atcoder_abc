#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
struct edge{
  int to,weight;
  edge(int to,int weight):to(to),weight(weight){}
};
using Graph = vector<vector<int>> ;
using GraphEdge = vector<vector<int>> ;
long long modinv(long long a, long long m=MOD) {long long b = m, u = 1, v = 0;while (b) {    long long t = a / b;    a -= t * b; swap(a, b);    u -= t * v; swap(u, v);}u %= m; if (u < 0) u += m;return u;}
//MODの割り算の際にa/＝b;をa *= modinv(b,MOD);とする。
int gcd(int a, int b){if (a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}
int main(){
  int r1,r2,c1,c2;cin >> r1 >> c1 >> r2 >> c2;
  int x = abs(r2-r1);
  int y = abs(c2-c1);
  
  if(x==0 && y == 0)cout << 0 << endl;
  else if((r1+c1 == r2 + c2) || (r1-c1 == r2-c2) || (abs(r1-r2) + abs(c1-c2) <= 3)){
    cout << 1 << endl;return 0;
  }
  else if(x == 0 || y == 0){
    int t = x+y;
    if(t%2 == 0){
      cout << 2 << endl;
    }else{
      if(t<7)cout << 2 << endl;
      else cout << 3 << endl;
    }
  }else if(x>y) {
    x-=y;
    y = 0;
    if(x%2 == 0){
      cout << 2 << endl;
    }else{
      if(x<4)cout << 2 << endl;
      else cout << 3 << endl;
    }
  }else{
    y-=x;
    x = 0;
    if(y%2 == 0){
      cout << 2 << endl;
    }else{
      if(y < 4)cout << 2 << endl;
      else cout << 3 << endl;
    }
  }

  return 0;
}