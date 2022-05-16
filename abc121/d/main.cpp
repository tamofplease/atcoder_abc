// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

int main() {
    ll a, b;
    cin >> a >> b;
    if (b % 2 == 1) {
        b = (b / 2 + 1) % 2;
    } else {
        b = b ^ ((b / 2) % 2);
    }
    if (a == 0) {
        cout << b << endl;
        return 0;
    }
    a--;
    if (a % 2 == 1) {
        a = (a / 2 + 1) % 2;
    } else {
        a = a ^ ((a / 2) % 2);
    }
    cout << (a ^ b) << endl;
    return 0;
}
