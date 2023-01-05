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
    int n, z, w;
    cin >> n >> z >> w;
    n += 2;
    vector<ll> a(n);
    a[0] = z;
    a[1] = w;
    for (int i = 2; i < n + 2; i++) cin >> a[i];
    if (n == 3) {
        cout << abs(a[2] - a[1]) << endl;
        return 0;
    }
    cout << max(abs(a[n - 1] - a[1]), abs(a[n - 1] - a[n - 2])) << endl;
    return 0;
}
