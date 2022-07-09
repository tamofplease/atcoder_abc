// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s[i] != t[j]) {
            if (i > 1) {
                if (s[i - 1] == s[i - 2] && s[i - 2] == t[j]) {
                    j++;
                    continue;
                }
            }
            puts("No");
            return 0;
        }
        i++;
        j++;
    }
    while (i > 1 && j < m && s[i - 1] == s[i - 2] && s[i - 1] == t[j]) {
        j++;
    }
    if (i == n && j == m) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}
