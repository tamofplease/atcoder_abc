#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}
ll X,Y;

void solve(){
  if((X+Y)%3!=0){
    cout << 0 << endl;
    return ;
  }
  ll manu = (X+Y)/3;
  ll m = (2*X-Y)/3;
  ll n = (2*Y-X)/3;
  if(m<0||n<0){
    cout << 0 << endl;
    return ;
  }
  ll ans = 1;
  for(int i=1;i<=manu;i++){
    ans *= i;
    ans %=MOD;
  }
  for(int i=1;i<=m;i++){
    ans *= modinv(i,MOD);
    ans %=MOD;
  }
  for(int i=1;i<=n;i++){
    ans *= modinv(i,MOD);
    ans %= MOD;
  }
  cout << (MOD+ans)%MOD << endl;
}

int main(){
    cin >> X >> Y;
    solve();
    return 0;
}