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
    int n, k;
    cin >> n >> k;
    int cur = ((n - 2) * (n - 1)) / 2;
    if (cur < k) {
        cout << -1 << endl;
        return 0;
    }
    vector<pair<int, int>> ans;
    Rep(i, n - 1) {
        ans.emplace_back(1, i + 1);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (cur == k)
                break;
            ans.emplace_back(i, j);
            cur--;
        }
    }
    cout << ans.size() << endl;
    for (pair<int, int> a : ans) {
        cout << a.first << " " << a.second << endl;
    }


    return 0;
}
