// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

const int MOD = 1000000007;

int main() {
    string s, t;
    cin >> s >> t;
    int sl = s.length(), tl = t.length();
    vector<vector<int>> v(26);
    rep(i, sl) { v[s[i] - 'a'].push_back(i); }
    rep(i, tl) {
        if (v[t[i] - 'a'].size() == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    vector<int>& tgt = v[t[0] - 'a'];
    auto it = lower_bound(ALL(tgt), -1);
    ll ans = (*it) + 1;
    ll cur = *it;
    Rep(i, tl - 1) {
        vector<int>& tgt = v[t[i] - 'a'];
        it = upper_bound(ALL(tgt), cur);
        if (it != tgt.end()) {
            ans += (*it) - cur;
            cur = *it;
        } else {
            it = lower_bound(ALL(tgt), 0);
            ans += sl - cur + (*it);
            cur = *it;
        }
    }
    cout << ans << endl;
    return 0;
}
