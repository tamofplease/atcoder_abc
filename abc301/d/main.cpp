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
    string s;
    cin >> s;
    ll n;
    cin >> n;
    ll cur = 0;
    ll m = 1;
    vector<ll> candidates;
    reverse(s.begin(), s.end());
    for (char c : s) {
        if (c == '?') {
            candidates.push_back(m);
        }
        if (c == '1') {
            cur += m;
        }
        m <<= 1;
    }
    if (cur > n) {
        cout << -1 << endl;
        return 0;
    }
    reverse(candidates.begin(), candidates.end());
    for (ll c : candidates) {
        if (cur <= n - c) cur += c;
    }
    cout << cur << endl;
    return 0;
}
