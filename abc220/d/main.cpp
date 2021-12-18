#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
using mint = modint998244353;

int main() {
    int N;cin >> N;
    vector<int> A(N);
    rep(i, N)cin >> A[i];
    vector<mint> dp(10);
    dp[A[0]] = 1;
    Rep(i, N-1) {
        int na = A[i];
        vector<mint> p(10);
        swap(p, dp);
        rep(j, 10) {
            dp[(j*na) % 10] += p[j];
            dp[(j+na) % 10] += p[j];
        }
    }
    rep(i, 10) {
        cout << dp[i].val() << endl;
    }
    return 0;
}
