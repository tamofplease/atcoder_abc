// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

#define ll int64_t

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> tmp(k);
    rep(i, n) { cin >> a[i]; }
    rep(i, n) { tmp[i % k].push_back(a[i]); }
    rep(i, k) { sort(tmp[i].begin(), tmp[i].end()); }
    rep(i, n) { a[i] = tmp[i % k][i / k]; }
    rep(i, n - 1) {
        if (a[i] > a[i + 1]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
