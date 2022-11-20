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
    int n;
    cin >> n;
    set<char> one = {'H', 'D', 'C', 'S'};
    set<char> two = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    bool ans = true;
    set<string> se;
    rep(i, n) {
        string s;
        cin >> s;
        se.insert(s);
        if (one.count(s[0]) && two.count(s[1])) continue;
        ans = false;
    }

    (ans && (se.size() == n)) ? puts("Yes") : puts("No");

    return 0;
}