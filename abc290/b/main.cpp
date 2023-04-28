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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string ans = "";
    for (char c : s) {
        if (c == 'x' || !k)
            ans.push_back('x');
        else {
            ans.push_back('o');
            k--;
        }
    }
    cout << ans << endl;

    return 0;
}
