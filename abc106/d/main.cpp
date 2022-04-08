#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main(){
    int N, M, Q; cin >> N >> M >> Q;
    vector<int> l(M), r(M);
    vector<int> city(n+1);
    rep(i,M) {
        int l, r;
        city[l]++; city[r]--;
    }
    rep(i, n) {
        city[i+1] += city[i];
    }
    rep(i, Q) {
        int p, q; cin >> p >> q;
    }
    return 0;
}
