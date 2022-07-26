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
    int n;
    cin >> n;
    map<vector<int>, ll> ma;
    rep(i, n) {
        string s;
        cin >> s;
        vector<int> v(26);
        for (char c : s) {
            v[c - 'a']++;
        }
        ma[v]++;
    }
    ll ans = 0;
    for (auto it : ma) {
        if (it.second > 1) {
            ans += (it.second * (it.second - 1)) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}
