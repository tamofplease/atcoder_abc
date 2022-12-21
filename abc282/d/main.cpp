// "Copyright 2022 tam"
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    vector<int> colors(n, 0);
    rep(i, m) {
        int a, b;
        cin >> a >> b, a--, b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    bool isValid = true;
    auto rec = [&](auto f, int cur) -> void {
        for (int nxt : to[cur]) {
            if (!colors[nxt]) {
                if (colors[nxt] == -colors[cur]) {
                    continue;
                }
                isValid = false;
                break;
            }
            colors[nxt] = -colors[cur];
            f(f, nxt);
        }
    };
    int cnt = 0;
    rep(i, n) {
        if (colors[i] != 0) continue;
        cnt++;
        colors[i] = cnt;
        rec(rec, i);
    }

    if (!isValid) {
        cout << 0 << endl;
        return 0;
    }
    map<int, int> count;
    for (int i : colors) {
        count[i]++;
    }
    ll ans = 0;
    rep(i, n) { ans += n - count[colors[i]] - to[i].size(); }

    cout << ans / 2 << endl;

    return 0;
}
