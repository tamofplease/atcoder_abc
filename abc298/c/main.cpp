// "Copyright 2022 tam"
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    int n, q;
    cin >> n >> q;
    vector<multiset<int>> boxes(n + 1);
    map<int, set<int>> ma;

    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, j;
            cin >> i >> j;
            boxes[j].insert(i);
            ma[i].insert(j);
        }

        if (t == 2) {
            int i;
            cin >> i;
            for (auto j : boxes[i]) cout << j << " ";
            cout << endl;
        }

        if (t == 3) {
            int i;
            cin >> i;
            for (int j : ma[i]) cout << j << " ";
            cout << endl;
        }
    }
    return 0;
}
