// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

int main() {
    int h, w;
    cin >> h >> w;
    vector<pair<int, int>> token;
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            char c = s[j];
            if (c == 'o') {
                token.push_back({i, j});
            }
        }
    }
    cout << abs(token[0].first - token[1].first) + abs(token[0].second - token[1].second) << endl;
    return 0;
}
