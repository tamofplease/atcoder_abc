// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

using mint = modint1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    k--;
    mint ans = 0;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(ALL(a));
    int left = k;
    mint c = 1;  // (k - 1)C(k - 1)
    for (int i = k; i < n; i++) {
        ans += (a[i] - a[n - i - 1]) * c;
        c *= (left + 1);
        c /= (left - (k - 1));
        left++;
    }
    cout << ans.val() << endl;
    return 0;
}
