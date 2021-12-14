#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int N;
const int MAXN = 200000;
ll A[MAXN];

void input() {
    cin >> N;
    rep(i,N) cin >> A[i];
}

// i番目の動作におけるゴール地点
ll B[MAXN];

/// i番目の動作における終了地点
ll C[MAXN];

/// i番目の動作における最高地点
ll D[MAXN];

// 2, -1, -2

// B: 2, -1, -1

// C: 2, 1, 0

void solve() { 
    B[0] = A[0];
    Rep(i, N-1) {
        B[i] = A[i] + B[i-1];
    }
    C[0] = B[0];
    Rep(i, N-1) {
        C[i] = B[i] + C[i-1];
    }

    D[0] = A[0];
    ll ans = 0;
    Rep(i, N-1) {
        D[i] = max(D[i-1], B[i-1] + A[i]);
        ans = max(ans, C[i-1] + D[i]);
    }
    cout << ans << endl;
}

int main(){
    input();
    solve();
    return 0;
}
