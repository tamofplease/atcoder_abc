// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

#define ll int64_t

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &ref : a)
        cin >> ref;
    vector<int> ans(n, 0);
    rep(i, n) {
        rep(j, i + 1) { ans[j] += a[i]; }
    }
    int p = 0;
    rep(i, n) {
        if (ans[i] >= 4)
            p++;
    }
    cout << p << endl;
    return 0;
}
