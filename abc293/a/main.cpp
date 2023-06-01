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
    string s;
    cin >> s;
    for (int i = 1; i <= s.length() / 2; i++) {
        swap(s[2 * i - 2], s[2 * i - 1]);
    }
    cout << s << endl;
    return 0;
}
