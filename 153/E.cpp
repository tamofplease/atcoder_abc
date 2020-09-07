#include <iostream>
#define MOD 1000000007
using namespace std;
#define INF 1000000001
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)

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

int N,H;
const int MAXN = 1002;
const int MAXH = 10001;
// const int MAXH_T = 20001;
ll dp[MAXN][MAXH*2+1];
ll A[MAXN],B[MAXH];
int main(){
    cin >> N >> H;
    rep(i,H)cin>> A[i] >> B[i];

    rep(i,MAXN)rep(j,MAXH*2)dp[i][j] = INT64_MAX;
    rep(i,MAXN)dp[i][0] = 0;
    rep(i,H){
        Rep(j,MAXH*2){
            if(i>0)dp[i][j] = min(dp[i][j],dp[i-1][j]);
            dp[i][j] = min(dp[i][j],(((j-1)/A[i])+1)*B[i]);
            if(i>0 && j-A[i]>=0)dp[i][j] = min(dp[i][j], dp[i-1][j-A[i]]+B[i]);
        }
    }
    ll ans = __LONG_LONG_MAX__;
    for(int i=N-1;i<MAXH*2;i++){
        // cout << dp[H-1][i] << " ";
        ans = min(dp[H-1][i], ans);
    }
    cout << ans << endl;
    return 0;
}