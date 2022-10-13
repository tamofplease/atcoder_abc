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
vector<int> toBinVector(ll n) {
    vector<int> res;
    int cnt = 0;
    while (n > 0) {
        if (n % 2) {
            res.push_back(cnt);
        }
        n /= 2;
        cnt++;
    }
    return res;
}

ll vecToInt(vector<int> v) {
    ll res = 0;
    for (int vv : v) res += (1 << vv);
    return res;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> ans;
    for (ll t = n;; t = (t - 1) & n) {
        ans.push_back(t);
        if (t == 0) break;
    }
    sort(ALL(ans));
    for (ll a : ans) cout << a << endl;
    return 0;
}
