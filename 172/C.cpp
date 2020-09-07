#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
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

const int MAXM = 200001;
ll A[MAXM];
ll B[MAXM];

int main(){
    ll N,M,K;cin >> N >> M >> K;
    A[0] = 0;
    Rep(i,N){
        cin >> A[i];
    }
    rep(i,N)A[i+1] += A[i];
    B[0] = 0;
    Rep(i,M)cin >> B[i];
    rep(i,M)B[i+1] += B[i];
    ll cursor = M;
    ll ans = 0;
    rep(i,N+1) {
        ll tmp = A[i] + B[cursor];
        while(tmp > K && cursor>0){
            cursor--;
            tmp = A[i] + B[cursor];
        }
        if(tmp > K)break;
        ll ma = i + cursor;
        ans = max(ma,ans);
    }


    
    
    
    
    cout << ans << endl;
    
    return 0;
}