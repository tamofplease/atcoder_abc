// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    int n;
    cin >> n;
    vector<int> m(n);
    vector<vector<int>> p(n), e(n);
    unordered_map<int, pair<int, int>> ma;
    rep(i, n) {
        cin >> m[i];
        vector<int> pp(m[i]), ee(m[i]);
        int mm = m[i];
        rep(j, mm) { cin >> pp[j] >> ee[j]; }
        e[i] = ee;
        p[i] = pp;
    }
    rep(i, n) {
        int mm = m[i];
        rep(j, mm) {
            int pp = p[i][j];
            int ee = e[i][j];
            if (ma.find(p[i][j]) == ma.end()) {
                ma[pp] = {ee, 1};
            } else {
                if (ma[pp].first < ee) {
                    ma[pp] = {ee, 1};
                } else if (ma[pp].first == ee) {
                    ma[pp].second++;
                }
            }
        }
    }
    int ans = 0;
    bool all = false;
    rep(i, n) {
        bool required = false;
        int mm = m[i];
        rep(j, mm) {
            if (ma[p[i][j]].first == e[i][j] && ma[p[i][j]].second == 1) {
                required = true;
            }
        }
        ans += required;
        if (!required) {
            all = true;
        }
    }
    cout << all + ans << endl;

    return 0;
}
