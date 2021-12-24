#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int N, M;cin >> N >> M;
    vector<int> H(N), W(M);
    rep(i, N) cin >> H[i];
    rep(i, M) cin >> W[i];
    sort(H.begin(), H.end());
    sort(W.begin(), W.end());
    int w_cur = 0;
    rep(i, N) {
        auto cursor = lower_bound(H.begin(), H.end(), W[w_cur]);
        
    }

    return 0;
}
