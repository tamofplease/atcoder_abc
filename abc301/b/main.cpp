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
    vector<int> a(n);
    rep(i, n) { cin >> a[i]; }
    vector<int> ans;
    int prev = -1;
    for (int cur : a) {
        if (prev == -1) {
            ans.push_back(cur);
            prev = cur;
            continue;
        }
        if (cur > prev) {
            for (int i = prev + 1; i <= cur; i++) {
                ans.push_back(i);
            }
        }
        if (prev > cur) {
            for (int i = prev - 1; i >= cur; i--) {
                ans.push_back(i);
            }
        }
        prev = cur;
    }
    for (int n : ans) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
