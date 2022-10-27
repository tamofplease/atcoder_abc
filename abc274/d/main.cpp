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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    unordered_set<int> ver, hor;
    ver.insert(0);
    hor.insert(a[0]);
    Rep(i, n - 1) {
        unordered_set<int> nxt;
        unordered_set<int>& tgt = (i & 1) ? ver : hor;
        for (const int ele : tgt) {
            nxt.insert(ele + a[i]);
            nxt.insert(ele - a[i]);
        }
        tgt = move(nxt);
    }
    hor.count(x) && ver.count(y) ? puts("Yes") : puts("No");
    return 0;
}
