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
    vector<vector<int>> a(n);
    vector<int> s(q), t(q);
    rep(i, n) {
        int l;
        cin >> l;
        rep(j, l) {
            int aa;
            cin >> aa;
            a[i].push_back(aa);
        }
    }
    rep(i, q) { cin >> s[i] >> t[i], s[i]--, t[i]--; }
    rep(i, q) { cout << a[s[i]][t[i]] << endl; }
    return 0;
}
