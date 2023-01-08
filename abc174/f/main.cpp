// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/fenwicktree>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define rRep(i, n) for (int i = n; i >= 1; i--)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> c(n), ans(q);
    for (int& ref : c) cin >> ref;
    vector<int> ma(n + 1, -1);
    vector<vector<int>> range_and_query;
    map<vector<int>, vector<int>> m;
    rep(i, q) {
        int l, r;
        cin >> l >> r, l--;
        range_and_query.push_back({l, 0, r});
        m[{l, 0, r}].push_back(i);
    }
    rep(i, n) {
        if (ma[c[i]] != -1) range_and_query.push_back({ma[c[i]], 1, i});
        ma[c[i]] = i;
    }
    sort(ALL(range_and_query), greater<vector<int>>());
    atcoder::fenwick_tree<int> fw(n);
    for (const vector<int>& v : range_and_query) {
        if (v[1]) {
            fw.add(v[2], 1);
            continue;
        }
        int a = v[2] - v[0] - fw.sum(0, v[2]);
        for (const int& mm : m[v]) ans[mm] = a;
    }
    for (const int& aa : ans) cout << aa << endl;

    return 0;
}
