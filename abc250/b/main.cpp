// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<char>> table(a*n, vector<char>(b*n));
    rep(i, n) {
        rep(j, n) {
            rep(k, a) rep(l, b) {
                table[k + i * a][l + j * b] = ((i + j) % 2 == 0)?'.':'#';
            }
        }
    }
    rep(i, n * a) {
        rep(j, n * b) {
            cout << table[i][j];
        }
        cout << endl;
    }
    return 0;
}
