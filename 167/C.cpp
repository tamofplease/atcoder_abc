#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

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
#define MAXN 12


int Solve[MAXN];
int N,M,X;

int C[MAXN], A[MAXN][MAXN];

bool check() {
    for(int i=0;i<M;i++) {
        if(Solve[i] < X)return false;
    }
    return true;
}


int main(){

    cin >> N >> M >> X;

    rep(i,N){
        cin >> C[i];
        rep(j,M)cin >> A[i][j];
    }

    rep(i,N) Solve[i] = 0;
    ll ans = 10000000;
    ll tmp = 0;

    for(int i=0;i<(1<<N);i++) {
        for(int j=0;j<N;j++) {
            if(i&(1<<j)) {
                for(int k=0;k<M;k++) {
                    Solve[k] += A[j][k];
                }
                tmp += C[j];
            }
        }
        if(check()){
            ans = min(tmp,ans);
        }
        tmp = 0;
        for(int k=0;k<M;k++)Solve[k] = 0;
    }
    if(ans == 10000000)cout << -1 << endl;
    else cout << ans << endl;
}