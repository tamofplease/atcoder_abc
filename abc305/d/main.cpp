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
    int n;
    cin >> n;
    set<int> a;
    set<int> whole;
    rep(i, n) {
        int aa;
        cin >> aa;
        a.insert(aa);
        whole.insert(aa);
    }

    int q;
    cin >> q;
    vector<int> l(q), r(q);
    rep(i, q) {
        cin >> l[i] >> r[i];
        whole.insert(l[i]);
        whole.insert(r[i]);
    }

    map<int, int> memo;
    bool isSleep = true;
    ll sleepTimes = 0;
    int prev = 0;
    for (int w : whole) {
        if (isSleep) {
            sleepTimes += w - prev;
        }
        memo[w] = sleepTimes;
        if (a.count(w)) {
            isSleep = !isSleep;
        }
        prev = w;
    }

    rep(i, q) { cout << memo[r[i]] - memo[l[i]] << endl; }

    return 0;
}
