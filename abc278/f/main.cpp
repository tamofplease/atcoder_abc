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

int to[26][26];

int main() {
    int n;
    cin >> n;
    memset(to, 0, sizeof(to));
    rep(i, n) {
        string s;
        cin >> s;
        to[s[0] - 'a'][s[s.length() - 1] - 'a']++;
    }
    auto canWin = [&](auto f, int cur) -> bool {
        for (int i = 0; i < 26; i++) {
            if (to[cur][i] == 0) continue;
            to[cur][i]--;
            bool next_is_win = f(f, i);
            to[cur][i]++;
            if (!next_is_win) {
                return true;
            }
        }
        return false;
    };
    for (int i = 0; i < 26; i++) {
        if (canWin(canWin, i)) {
            puts("First");
            return 0;
        }
    }

    puts("Second");
    return 0;
}
