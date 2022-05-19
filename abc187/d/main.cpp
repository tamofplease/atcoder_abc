// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

int main() {
    int n;
    cin >> n;
    ll border = 0;
    vector<ll> data(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        border += a;
        data[i] = -a * 2 - b;
    }
    sort(data.begin(), data.end());
    ll cur = 0;
    int i = 0;
    while (cur <= border) {
        cur += data[i] * -1;
        i++;
    }
    cout << i << endl;

    return 0;
}
