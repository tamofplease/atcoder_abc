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
    string t;
    cin >> t;
    string s1 = t.substr(0, n), s2 = t.substr(n, 2 * n);
    reverse(s2.begin(), s2.end());
    if (s1 == s2) {
        cout << s1 << " " << n << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        char c = s1.back();
        s1.pop_back();
        s1.push_back(s2.back());
        s2.push_back(c);
        cout << s1 << " " << s2 << endl;
        int same = 0;
        for (int j = 0; j < n; j++) {
            if (s1[j] != s2[j + i + 1]) break;
            same++;
        }
        if (same == n) {
            cout << s1 << endl;
        }
    }

    return 0;
}
