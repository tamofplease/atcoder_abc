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
    vector<string> s(n);
    for (auto& ref : s) {
        cin >> ref;
    }
    int ans = INT32_MAX;
    vector<vector<int>> ma(10, vector<int>(10, 0));
    for (string ss : s) {
        rep(i, 10) {
            char c = ss[i];
            ma[c - '0'][i]++;
        }
    }
    rep(i, 10) {
        /// first回secondに現れる。
        pair<int, int> cur_max = {0, 0};
        rep(j, 10) {
            if (cur_max.first < ma[i][j]) {
                cur_max = {ma[i][j], j};
            }
            if (cur_max.first == ma[i][j]) {
                if (cur_max.second < j) {
                    cur_max = {ma[i][j], j};
                }
            }
        }
        ans = min(ans, 10 * (cur_max.first - 1) + cur_max.second);
    }
    cout << ans << endl;
    return 0;
}
