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
    vector<bool> called(n, false);
    rep(i, n) {
        int a;
        cin >> a, a--;
        if (!called[i]) called[a] = true;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += !called[i];
    }
    cout << ans << endl;

    for (int i = 0; i < n; i++) {
        if (!called[i]) cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}