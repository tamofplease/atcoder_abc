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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> odds, evens;
    for (const int aa : a) {
        ((aa % 2) ? odds : evens).push_back(aa);
    }
    if (odds.size() == 1 && evens.size() == 1) {
        puts("-1");
        return 0;
    }
    int ans = 0;
    if (odds.size() > 1) ans = max(ans, odds[odds.size() - 1] + odds[odds.size() - 2]);
    if (evens.size() > 1) ans = max(ans, evens[evens.size() - 1] + evens[evens.size() - 2]);
    cout << ans << endl;
    return 0;
}
