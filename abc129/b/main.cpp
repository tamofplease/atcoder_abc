// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define Rep(i, n) for (int i = 1 ; i <= n ; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    int a, b = 0;
    for (auto& ref : w) {
        cin >> ref;
        a += ref;
    }
    int ans = abs(a - b);
    for (int ww : w) {
        a -= ww;
        b += ww;
        ans = min(ans, abs(a - b));
    }
    cout << ans << endl;
    return 0;
}
