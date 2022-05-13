// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64

int main() {
    int h, w;
    cin >> h >> w;
    int r, c;
    cin >> r >> c;
    cout << 4 - ( r == 1 ) - ( r == h ) - ( c == 1 ) - ( c == w ) << endl;
    return 0;
}