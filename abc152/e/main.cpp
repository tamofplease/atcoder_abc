// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;
using mint = modint1000000007;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> ma;
    vector<unordered_map<int, int>> hold(n);
    for (unordered_map<int, int>& h : hold) {
        int a;
        cin >> a;
        for (int j = 2; j * j <= a; j++) {
            int cnt = 0;
            while (a % j == 0) a /= j, cnt++;
            if (cnt > 0) h[j] = cnt;
        }
        if (a != 1) h[a] = 1;
        for (auto it : h) ma[it.first] = (ma.find(it.first) == ma.end() ? it.second : max(ma[it.first], it.second));
    }
    mint ans = 0;
    for (unordered_map<int, int>& cur : hold) {
        mint c = 1;
        for (auto it : ma) {
            mint cc = 1;
            int dist = it.second - ((cur.find(it.first) == cur.end()) ? 0 : cur[it.first]);
            rep(j, dist) cc *= it.first;
            c *= cc;
        }
        ans += c;
    }
    cout << ans.val() << endl;

    return 0;
}
