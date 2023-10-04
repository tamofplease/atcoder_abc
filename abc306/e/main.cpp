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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> box(n, 0);
    multiset<int> cnt, other;
    rep(i, k) { cnt.insert(0); }
    rep(i, n - k) { other.insert(0); }
    ll ans = 0;
    rep(i, q) {
        assert(cnt.size() == k);
        assert(other.size() == n - k);
        int x, y;
        cin >> x >> y, x--;
        int prev = box[x];
        box[x] = y;

        // 計算に利用されていないケース
        if (other.count(prev)) {
            other.erase(other.find(prev));
            int cntMin = *(cnt.begin());
            if (cntMin < y) {
                cnt.erase(cnt.find(cntMin));
                other.insert(cntMin);
                cnt.insert(y);
                ans += y - cntMin;
            } else {
                other.insert(y);
            }
        } else {
            // 計算に利用されているケース
            int otherMax;
            if (other.size()) {
                otherMax = *(other.rbegin());

            } else {
                otherMax = INT32_MIN;
            }
            cnt.erase(cnt.find(prev));
            if (otherMax < y) {
                cnt.insert(y);
                ans -= prev;
                ans += y;
            } else {
                other.erase(other.find(otherMax));
                cnt.insert(otherMax);
                other.insert(y);
                ans -= prev;
                ans += otherMax;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
