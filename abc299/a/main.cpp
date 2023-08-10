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
    string s;
    cin >> n >> s;
    int left = -1, right = -1, mid = -1;
    rep(i, n) {
        if (s[i] == '|') {
            if (left == -1)
                left = i;
            else
                right = i;
        }
        if (s[i] == '*') mid = i;
    }
    if (left < mid && mid < right)
        puts("in");
    else
        puts("out");
    return 0;
}
