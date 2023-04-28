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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& ref : a) cin >> ref;
    for (auto& ref : b) cin >> ref;

    cout << accumulate(b.begin(), b.end(), 0, [&a](const int prev, const int cur) { return prev + a[cur - 1]; })
         << endl;
    return 0;
}
