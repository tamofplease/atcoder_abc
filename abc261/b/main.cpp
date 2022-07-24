// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) rep(j, n) {
        if (i == j) {
            continue;
        }
        if (a[i][j] == 'W' && a[j][i] == 'L') {
            continue;
        }
        if (a[i][j] == 'L' && a[j][i] == 'W') {
            continue;
        }
        if (a[i][j] == 'D' && a[j][i] == 'D') {
            continue;
        }
        puts("incorrect");
        return 0;
    }
    puts("correct");

    return 0;
}
