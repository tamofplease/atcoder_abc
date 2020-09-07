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
int main(){
    int N,M;cin >> N >> M;
    const int MAXM=100001;
    int L[MAXM],R[MAXM];
    int maxl = 0,minr = MAXM;
    rep(i,M){
        cin >> L[i] >> R[i];
        maxl = max(maxl,L[i]);
        minr = min(minr,R[i]);
    }
    int ans = 0;
    Rep(i,N){
        if(maxl<=i && minr >= i)ans++;
    }

    cout << ans << endl;

    return 0;
}