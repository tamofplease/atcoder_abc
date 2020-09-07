#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,N) for(int i=1;i<=n;i++)

long long modinv(long long a, long long m=MOD) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
    /*MODの割り算の際に
    a/＝b;
    を
    a *= modinv(b,MOD);
    とする。
        */
}
int N;
const int MAXN = 16;

int A[MAXN];
int x[MAXN][MAXN];
int y[MAXN][MAXN];

bool valid(bool truer[]) {
  rep(i,N) {
    if(!truer[i+1])continue;
    rep(j,A[i]) {
      if(truer[x[i][j]] != y[i][j]){
        return false;
      }
    }
  }
  return true;
}


int main(){
    cin >> N;
    rep(i,N) {
      cin >> A[i];
      rep(j,A[i]) {
        cin >> x[i][j] >> y[i][j];
      }
    }
    int ans = 0;
    for(int i=0;i<(1<<N);i++) {
      int num = 0;
      bool truer[N+1];
      for(int bit =0;bit < N ; bit++) {
        if(i&(1<<bit)){
          num++;
          truer[bit+1] = true;
        }else {
          truer[bit+1] = false;
        }
      }
      if(valid(truer)){
        ans = max(num,ans);
      }
    }
    cout << ans << endl;
    return 0;
}