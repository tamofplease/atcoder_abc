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

int genKey(int ct, int ca) { return ct * 2001 + ca; }

int solve() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    vector<vector<int>> red(n), blue(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v, u--, v--;
        (c[u] ? blue[u] : red[u]).push_back(v);
        (c[v] ? blue[v] : red[v]).push_back(u);
    }
    vector<int> memo(2001 * 2001, -1);

    memo[genKey(0, n - 1)] = 0;
    // {taka, aoki}
    queue<pair<int, int>> q;
    q.emplace(0, n - 1);
    while (!q.empty()) {
        auto [ct, ca] = q.front();
        int prev_key = genKey(ct, ca);
        q.pop();

        // t=> red, a=>blue
        for (int nt : red[ct]) {
            for (int na : blue[ca]) {
                int key = genKey(nt, na);
                if (memo[key] != -1) continue;

                if (nt == n - 1 && na == 0) return memo[prev_key] + 1;

                memo[key] = memo[prev_key] + 1;

                q.emplace(nt, na);
            }
        }

        // t=>blue, a=>red;
        for (int nt : blue[ct]) {
            for (int na : red[ca]) {
                int key = genKey(nt, na);

                if (memo[key] != -1) continue;

                if (nt == n - 1 && na == 0) return memo[prev_key] + 1;

                memo[key] = memo[prev_key] + 1;

                q.emplace(nt, na);
            }
        }
    }
    return memo[genKey(n - 1, 0)];
}

int main() {
    int t;
    cin >> t;
    rep(i, t) {
        int ans = solve();
        cout << ans << endl;
    }
    return 0;
}
