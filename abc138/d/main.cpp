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
    int n, q;
    cin >> n >> q;
    vector<int> cnt(n, 0);
    vector<vector<int>> to(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b, a--, b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    rep(i, q) {
        int qq, x;
        cin >> qq >> x, qq--;
        cnt[qq] += x;
    }
    queue<pair<int, int>> que;
    que.emplace(0, -1);
    while (!que.empty()) {
        auto [cur, prev] = que.front();
        que.pop();
        if (prev != -1) {
            cnt[cur] += cnt[prev];
        }
        for (int nxt : to[cur]) {
            if (nxt == prev) continue;
            que.emplace(nxt, cur);
        }
    }
    rep(i, n) {
        if (i) cout << " ";
        cout << cnt[i];
    }
    cout << endl;

    return 0;
}
