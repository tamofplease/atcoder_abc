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
    int n, q;
    cin >> n >> q;
    map<int, set<int>> v;
    rep(i, q) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            if (v.count(a))
                v[a].insert(b);
            else
                v[a] = {b};
        }
        if (t == 2) {
            if (v.count(a) && v[a].count(b)) v[a].erase(b);
        }
        if (t == 3) {
            (v.count(a) && v[a].count(b) && v.count(b) && v[b].count(a)) ? puts("Yes") : puts("No");
        }
    }
    return 0;
}
