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
    set<string> predefined = {"and", "not", "that", "the", "you"};
    int n;
    cin >> n;
    vector<string> w(n);
    rep(i, n) { cin >> w[i]; }
    for (string& ww : w) {
        if (predefined.count(ww)) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
