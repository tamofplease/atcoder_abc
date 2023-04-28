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
    vector<int> a(n * 5);
    rep(i, n * 5) { cin >> a[i]; }
    sort(ALL(a));

    int ans = 0;
    for (int i = n; i < 4 * n; i++) {
        ans += a[i];
    }
    printf("%.10f\n", (double)((double)ans / (3 * n)));
    return 0;
}
