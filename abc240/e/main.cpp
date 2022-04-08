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
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> to(n);
    rep(i,n-1) {
        int u, v; cin >> u >> v;
        u--;v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    int current_front = 1;
    vector<pair<int, int>> ans(n);

    auto dfs = [&](auto f, int cur, int prev=-1) -> pair<int,int> {
        if(to[cur].size() == 1 && to[cur][0] == prev) {
            ans[cur] = {current_front, current_front};
            current_front++;
        } else {
            int left = INT32_MAX, right = 0;
            for(int nxt: to[cur]) {
                if(nxt == prev) continue;
                pair<int, int> p = f(f, nxt, cur);
                left = min(left, p.first);
                right = max(right, p.second);
            }
            ans[cur] = {left, right};
        }
        return ans[cur];
    };

    dfs(dfs, 0);
    for(auto p : ans)  {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
