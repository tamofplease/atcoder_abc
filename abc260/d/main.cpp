// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define Rep(i, n) for (int i = 1 ; i <= n ; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    vector<int> ans(n, -1);
    set<int> table;
    map<int, vector<int>> ma;
    rep(i, n) {
        int p;
        cin >> p;
        auto it = table.lower_bound(p);
        if (it == table.end()) {
            if (k == 1) {
                ans[p - 1] = i + 1;
                continue;
            }
            table.insert(p);
            ma[p] = { p };
            continue;
        }
        int tgt = *it;
        table.erase(tgt);
        table.insert(p);
        ma.emplace(p, move(ma[tgt]));
        ma[p].push_back(p);
        ma.erase(tgt);

        if (static_cast<int>(ma[p].size()) == k) {
            for (int m : ma[p]) {
                ans[m - 1] = i + 1;
            }
            ma.erase(p);
            table.erase(p);
        }
    }
    for (int a : ans) {
        cout << a << endl;
    }
    return 0;
}
