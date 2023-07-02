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
    vector<int> first;
    int second = 0;
    for (int i = 0; i < 8; i++) {
        if (s[i] == 'B') {
            first.push_back(i);
        }
        if (s[i] == 'K' && second == 1) second++;
        if (s[i] == 'R' && second != 1) second++;
    }
    if ((first[0] + first[1]) % 2 == 0 || second != 3) {
        puts("No");
        return 0;
    }
    puts("Yes");
    return 0;
}
