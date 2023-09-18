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
    map<char, int> ma1, ma2;
    for (char c : s) ma1[c]++;
    for (char c : t) ma2[c]++;
    string base = "atcoder";
    rep(i, 26) {
        char c = i + 'a';
        if (base.find(c) != string::npos) continue;
        if (ma1.count(c) && ma2.count(c) && ma1[c] == ma2[c]) {
            continue;
        }
        if (!ma1.count(c) && !ma2.count(c)) continue;
        puts("No");
        return 0;
    }
    int s_whild = ma1.count('@') ? ma1['@'] : 0;
    int t_whild = ma2.count('@') ? ma2['@'] : 0;
    for (char c : base) {
        if (ma1.count(c) && ma2.count(c)) {
            if (ma1[c] > ma2[c]) t_whild -= ma1[c] - ma2[c];
            if (ma1[c] < ma2[c]) s_whild -= ma2[c] - ma1[c];
            continue;
        }
        if (ma1.count(c)) {
            t_whild -= ma1[c];
        }
        if (ma2.count(c)) {
            s_whild -= ma2[c];
        }
    }

    if (s_whild < 0 || t_whild < 0) {
        puts("No");
    } else {
        puts("Yes");
    }

    return 0;
}
