// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    int r, c;
    cin >> r >> c;
    int a[3][3];
    Rep(i, 2) Rep(j, 2) cin >> a[i][j];
    cout << a[r][c] << endl;
    return 0;
}
