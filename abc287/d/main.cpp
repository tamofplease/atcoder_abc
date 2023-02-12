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
    string s, t;
    cin >> s >> t;
    const int n = s.length(), m = t.length();
    int diff = 0;

    function<bool(char, char)> isSame = [](const char a, const char b) -> bool {
        return a == '?' || b == '?' || a == b;
    };

    for (int i = 0; i < m; i++) {
        if (!isSame(s[i + n - m], t[i])) diff++;
    }

    if (diff == 0)
        puts("Yes");
    else
        puts("No");

    Rep(x, m) {
        if (!isSame(s[x - 1], t[x - 1])) {
            diff++;
        }
        if (!isSame(s[x - 1 + n - m], t[x - 1])) {
            diff--;
        }
        if (diff == 0)
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}
