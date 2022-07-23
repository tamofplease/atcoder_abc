// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

const int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> children(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b, a--, b--;
        children[a].push_back(b);
        children[b].push_back(a);
    }
    vector<int> colors(n, -1);
    queue<pair<int, int>> q;
    q.emplace(0, 1);
    colors[0] = k;
    while (!q.empty()) {
        auto [cur, depth] = q.front();
        q.pop();
        int init = k - min(2, depth);
        for (int child : children[cur]) {
            if (colors[child] != -1) {
                continue;
            }
            q.emplace(child, depth + 1);
            colors[child] = init;
            init--;
        }
    }
    ll ans = 1;
    for (int color : colors) {
        ans *= color;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
