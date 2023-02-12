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
    vector<string> s(n);
    unordered_map<string, vector<int>> ma;
    unordered_map<string, int> m;
    rep(i, n) {
        cin >> s[i];
        ma[s[i]].push_back(i);
    }
    sort(s.begin(), s.end());
    function<int(string, string)> getLCP = [](const string& a, const string& b) -> int {
        const int m = min(a.length(), b.length());
        for (int i = 0; i < m; i++) {
            if (a[i] != b[i]) return i;
        }
        return m;
    };
    int carry = 0;
    for (int i = 0; i < n - 1; i++) {
        if (m.count(s[i])) continue;
        int nxt = getLCP(s[i], s[i + 1]);
        m[s[i]] = max(nxt, carry);
        carry = nxt;
    }
    m[s[n - 1]] = carry;

    vector<int> ans(n, 0);
    for (const auto [t, i] : m) {
        for (int j : ma[t]) ans[j] = i;
    }
    for (const int a : ans) cout << a << endl;

    return 0;
}
