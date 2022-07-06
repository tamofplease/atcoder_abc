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
    int n, q;
    string s;

    cin >> n >> q;
    cin >> s;
    int cur = 0;
    rep(i, q) {
        int type, x, cur = 0;
        cin >> type >> x;
        if (type == 1) {
            cur = (cur - (x % n) + n) % n;
        } else {
            cout << s[((x + cur - 1) % n + n) % n] << endl;
        }
    }

    return 0;
}
