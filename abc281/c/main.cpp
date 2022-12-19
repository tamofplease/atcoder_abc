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
    long long n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (auto& ref : a) cin >> ref;
    ll sum = accumulate(ALL(a), (ll)0, [](ll cur, ll nxt) -> long long { return cur + nxt; });

    t %= sum;
    int i = 0;
    for (; i < n; i++) {
        if (t < a[i]) break;
        t -= a[i];
    }
    cout << i + 1 << " " << t << endl;

    return 0;
}
