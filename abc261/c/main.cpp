// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<string> ss(n);
    rep(i, n) { cin >> ss[i]; }
    map<string, pair<int, int>> ma;
    for (string s : ss) {
        if (ma.find(s) == ma.end()) {
            ma[s] = {1, 0};
        } else {
            ma[s].first++;
        }
    }

    for (string s : ss) {
        if (ma[s].first == 1 || ma[s].second == 0) {
            cout << s << endl;
            ma[s].second++;
            continue;
        }
        cout << s << "(" << ma[s].second << ")" << endl;
        ma[s].second++;
    }

    return 0;
}
