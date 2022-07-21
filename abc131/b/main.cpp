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
    int n, l;
    cin >> n >> l;
    int ans = 0;
    int eat = INT32_MAX;
    int ind = 0;
    rep(i, n) {
        ans += l + i;
        if (eat > abs(l + i)) {
            eat = abs(l + i);
            ind = i;
        }
    }
    cout << ans - (l + ind) << endl;
    return 0;
}
