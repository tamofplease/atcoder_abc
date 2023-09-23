// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

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
    vector<set<int>> base(n);
    vector<int> s, g;
    vector<vector<int>> g(m);
    dsu d(m);

    rep(i, n) {
        int a;
        cin >> a;
        rep(i, a) {
            int s;
            cin >> s;
            base[i].insert(s);
        }
    }

    Rep(i, m) {}

    return 0;
}
