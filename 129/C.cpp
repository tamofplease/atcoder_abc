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
const int MAXN = 100001;
const int MAXM = 100001;
ll dp[MAXN];
int main(){
    memset(dp,-1, sizeof(dp));
    int N,M; cin >> N >> M;
    int A[MAXM];
    dp[0] = 1;
    dp[1] = 1;
    rep(i,M){
        cin >> A[i];
        dp[A[i]] = 0;
    }
    for(int i=2;i<=N;i++){
        if(dp[i]!= 0)dp[i] = ((dp[i-1]%MOD) + (dp[i-2]%MOD))%MOD;
        dp[i] %= MOD;
    }
    cout << max((ll)0,dp[N]) << endl;
    return 0;
}