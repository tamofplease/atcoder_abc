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
    auto valid = [](string s) -> bool {
        if (s.length() != 8) return false;
        if (int(s[0]) < int('A') || int('Z') < int(s[0])) return false;
        if (int(s[7]) < int('A') || int('Z') < int(s[7])) return false;
        if (s[1] == '0') return false;
        for (int i = 1; i <= 6; i++) {
            int n = s[i] - '0';
            if (n < 0 || 9 < n) return false;
        }
        return true;
    };
    valid(s) ? puts("Yes") : puts("No");
    return 0;
}
