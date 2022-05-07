#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)

#define ll long long

int main() {
    int n; cin >> n;
    vector<int> c(n);
    vector<vector<int>> to(n);
    for(auto& ref : c) cin >> ref;
    rep(i,n-1) {
        int a, b; cin >> a >> b;
        a--;b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    unordered_set<int> visited;

    vector<int> ans;
    set<int> colors;
    auto dfs = [&](auto f, int cur) -> void {
        int color = c[cur];
        bool isColorAppend = false;
        if(colors.find(color) == colors.end()) {
            colors.insert(color);
            ans.push_back(cur);
            isColorAppend = true;
        }
        visited.insert(cur);
        for(int nxt : to[cur]) {
            if(visited.find(nxt) != visited.end()) continue;
            f(f, nxt);
        }
        visited.erase(cur);
        if(isColorAppend) colors.erase(color);
    };

    dfs(dfs, 0);

    sort(ans.begin(), ans.end());
    for(int an : ans) cout << an + 1 << endl;
    return 0;
}