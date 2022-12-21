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
    string s;
    cin >> s;
    bool isCovered = false;
    string ans = "";
    for (char c : s) {
        if (c == ',') {
            ans.push_back(isCovered ? ',' : '.');
            continue;
        }
        if (c == '"') {
            isCovered = !isCovered;
        }
        ans.push_back(c);
    }
    cout << ans << endl;
    return 0;
}
