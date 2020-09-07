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
    int p[11];
    int s[11][11];
    rep(i,10)rep(j,10)s[i][j] = -1;
    int k[11];
    rep(i,M){
        cin >> k[i];
        rep(j,k[i])cin >> s[i][j];
    }
    rep(i,M)cin >> p[i];
    ll ans = 0;
    for(int i=0;i<(1<<N);i++){
        bool flag = true;
        int tmp[12];
        memset(tmp,0,11*sizeof(int));
        for(int bit=0;bit<N;bit++){
            if(i&(1<<bit)){
                tmp[bit] = 1;
            }
        }
        rep(i,M){
            int count = 0;
            rep(j,k[i]){
                if(tmp[s[i][j]-1]==1){
                    count++;
                }
            }
            if((count%2)!=p[i])flag=false;
        }
        
        if(flag)ans++;
    }
    cout << ans << endl;
    return 0;
}