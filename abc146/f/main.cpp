// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    if (n <= m) {
        cout << 1 << " " << n << endl;
        return 0;
    }
    vector<int> step(n + 1, 0);
    Rep(i, m) { step[i] = s[i] == '1' ? -1 : 1; }
    for (int iter = m + 1; iter < n + 1; iter++) {
        int prev = step[iter - m];
        if (step[prev] == -1 || s[iter] == '1') {
            step[iter] = -1;
            continue;
        }
        step[iter] = step[prev] + 1;
    }
    rep(i, n + 1) { cout << step[i] << " "; }
    // cout << endl;
    // vector<int> ans;
    // int now = step[n];
    // int prevIndex = n;
    // for (int i = n; i >= 0; i--) {
    //     if (i == 0) {
    //         ans.push_back(prevIndex - i);
    //     }
    //     if (now - 1 == step[i] && step[i] == step[i - 1] + 1) {
    //         ans.push_back(prevIndex - i);
    //         prevIndex = i;
    //         now--;
    //     }
    // }
    // reverse(ans.begin(), ans.end());
    // int an = 0;

    // for (int aa : ans) {
    //     cout << aa << " ";
    // }
    return 0;
}
