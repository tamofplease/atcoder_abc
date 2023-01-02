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
    for (auto& ref : a) cin >> ref;
    int q;
    cin >> q;
    rep(i, q) {
        int j;
        cin >> j;
        if (j == 1) {
            int k, x;
            cin >> k >> x, k--;
            a[k] = x;
        }
        if (j == 2) {
            int k;
            cin >> k, k--;
            cout << a[k] << endl;
        }
    }

    return 0;
}
