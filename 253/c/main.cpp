// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

int main() {
    int q;
    cin >> q;
    map<int, int> ma;
    rep(i, q) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            ma[x]++;
        } else if (type == 2) {
            int x, c;
            cin >> x >> c;
            ma[x] = max(0, ma[x] - c);
            if (ma[x] == 0) {
                ma.erase(x);
            }
        } else {
            cout << ma.rbegin()->first - ma.begin()->first << endl;
        }
    }
    return 0;
}
