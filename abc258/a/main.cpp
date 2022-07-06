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
    int k;
    cin >> k;
    int hh = 21 + (k >= 60);
    k %= 60;
    int mm = k;
    cout << hh << ":";
    if (mm < 10) {
        cout << "0";
    }
    cout << mm << endl return 0;
}
