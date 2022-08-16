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
    vector<int> p(n), c(n);
    rep(i, n) cin >> p[i], p[i]--;
    rep(i, n) cin >> c[i];
    ll ans = INT32_MIN;

    // 1 3 4 0 2

    rep(start, n) {
        ll cur = c[start];
        ll oneLoopSize = 1, oneLoopGain = c[start];
        int nxt = p[start];
        while (nxt != start) {
            oneLoopSize++;
            oneLoopGain += c[nxt];
            nxt = p[nxt];
        }
        int loopNum = k / oneLoopSize;
        int surplus = k % oneLoopSize;
        nxt = p[start];
        if (oneLoopSize >= k || oneLoopGain < 0) {
            ll curMax = cur;
            rep(i, min(oneLoopSize, k) - 1) {
                cur += c[nxt];
                nxt = p[nxt];
                curMax = max(cur, curMax);
            }
            ans = max(ans, (ll)curMax);
            continue;
        }
        ll curMax = oneLoopGain * (loopNum - 1);
        cur = curMax;
        rep(i, surplus + oneLoopSize) {
            cur += c[nxt];
            nxt = p[nxt];
            curMax = max(cur, curMax);
        }
        ans = max(ans, (ll)curMax);
    }
    std::cout << ans << endl;

    return 0;
}
