#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int N, M;cin >> N >> M;
    vector<vector<int>> to(N);
    rep(i, M) {
        int a,b; cin >> a >> b;
        a--;b--;
        to[a].push_back(b);
    }
    atcoder::dsu d(N);
    int cur = 0;
    vector<int> ans(N);
    for(int i=N-1;i>=0;i--) {
        ans[i] = cur++;
        for(auto nxt: to[i]) {
            if(d.same(nxt, i)) continue;
            d.merge(nxt, i);
            cur--;
        }
    }
    rep(i, N) {
        cout << ans[i] << endl;
    }
    return 0;
}
