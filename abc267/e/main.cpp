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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int>> g(n);
    vector<ll> costs(n, 0);
    rep(i, m) {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v), g[v].push_back(u);
        costs[u] += a[v];
        costs[v] += a[u];
    }
    auto ok = [&](ll mid) -> bool {
        stack<int> st;
        vector<bool> valids(n, false);
        vector<ll> cs(n, 0);
        copy(ALL(costs), cs.begin());
        rep(i, n) if (cs[i] <= mid) {
            st.push(i);
            valids[i] = true;
        }
        while (st.size()) {
            int index = st.top();
            st.pop();
            for (int nxt : g[index]) {
                if (valids[nxt]) continue;
                cs[nxt] -= a[index];
                if (cs[nxt] <= mid) {
                    st.push(nxt);
                    valids[nxt] = true;
                }
            }
        }
        for (int valid : valids)
            if (!valid) return false;
        return true;
    };
    ll invalid = -1, valid = INT64_MAX / 2;
    while (valid - invalid > 1) {
        ll mid = (invalid + valid) / 2;
        (ok(mid) ? valid : invalid) = mid;
    }
    cout << valid << endl;

    return 0;
}
