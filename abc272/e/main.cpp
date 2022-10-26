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
    for (auto &v : a) cin >> v;
    vector<vector<int>> resp(m + 1);
    rep(i, n) {
        if (a[i] >= n) continue;
        int left = (a[i] >= 0 ? 1 : (-a[i] + i) / (i + 1));
        int right = min(m + 1, (n - a[i] + i) / (i + 1));
        for (int j = left; j < right; j++) resp[j].push_back(a[i] + j * (i + 1));
    }
    Rep(i, m) {
        int sz = resp[i].size();
        vector<bool> exi(sz + 1);
        for (auto v : resp[i]) {
            if (v < sz) exi[v] = true;
        }
        int it = 0;
        while (exi[it]) it++;
        cout << it << endl;
    }

    return 0;
}
