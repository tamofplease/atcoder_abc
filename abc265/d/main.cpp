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
    ll n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<pair<int, int>> pv, qv, rv;
    auto twoPointers = [&](const ll tgt, vector<pair<int, int>>& v) -> void {
        int back = 0;
        ll tmp = 0;
        for (int front = 0; front < n; front++) {
            tmp += a[front];
            if (tmp < tgt) continue;
            while (tgt < tmp) {
                tmp -= a[back++];
            }
            if (tgt == tmp) v.emplace_back(back, front);
        }
    };
    twoPointers(p, pv);
    twoPointers(q, qv);
    twoPointers(r, rv);
    set<int> ps, rs;
    for (pair<int, int> pp : pv) ps.insert(pp.second);
    for (pair<int, int> rr : rv) rs.insert(rr.first);
    for (pair<int, int> qq : qv) {
        if (ps.find(qq.first - 1) != ps.end() && rs.find(qq.second + 1) != rs.end()) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
