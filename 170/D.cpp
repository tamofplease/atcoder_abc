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
int N;
const int MAXN = 200001;
const int MAXA = 1000005;
int dp[MAXA]; //dp[i][j] iをjで割ったあまり
int A[MAXN];

bool ok[MAXN];
int same[MAXA];
int main(){
    cin >> N;
    rep(i,N)cin >> A[i];
    rep(i,MAXA){        
        same[i] = 0;
        dp[i] = false;
    }

    sort(A,A+N);
    int ans = 0;
    rep(i,N){
        if(same[A[i]]!=0){
            same[A[i]] = 2;
            continue;
        }else{
            for(int j=A[i];j<MAXA;j+=A[i])same[j]++;
        }
    }
    rep(i,N) {
        if(same[A[i]]==1)ans++;
    }
    
    cout << ans << endl;
    return 0;
}