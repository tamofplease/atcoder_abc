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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& ref : a) cin >> ref;
    for (int i = k; i < n; i++) cout << a[i] << " ";
    for (int i = 0; i < min(n, k); i++) cout << "0 ";
    cout << endl;

    return 0;
}
