// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define Rep(i, n) for (int i = 1 ; i <= n ; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    string s;
    cin >> s;
    rep(i, 3) {
        if (s[i] == s[i + 1]) {
            puts("Bad");
            return 0;
        }
    }
    puts("Good");
    return 0;
}