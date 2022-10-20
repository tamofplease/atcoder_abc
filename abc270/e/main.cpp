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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    // 1. prepare priority_queue
    // 2. pop and resume until, k < pq.top() * pq.size();
    // 3. update each a, and sub more if k and a[i] is not 0.
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (const ll aa : a)
        if (aa > 0) pq.push(aa);

    ll cur = 0;
    while (!pq.empty()) {
        ll top = pq.top();
        if ((top - cur) * (ll)pq.size() > k) break;
        k -= (top - cur) * pq.size();
        cur = top;
        while (!pq.empty() && pq.top() == top) pq.pop();
    }
    ll sub = pq.size() ? k / pq.size() : 0;
    for (ll& aa : a) aa = max((ll)0, aa - cur - sub);
    k = pq.size() ? k % pq.size() : 0;

    for (int i = 0;; i++) {
        i %= n;
        if (k == 0) break;
        if (a[i] > 0) {
            k--;
            a[i]--;
        }
    }
    for (const ll aa : a) cout << aa << " ";
    cout << endl;
    return 0;
}
