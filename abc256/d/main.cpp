// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

#define ll int64_t

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> rang(n);
    rep(i, n) { cin >> rang[i].first >> rang[i].second; }
    sort(rang.begin(), rang.end());
    /// -------
    ///   -------
    /// -------
    ///          -----
    /// ------
    ///  ---
    vector<pair<int, int>> ans;
    ans.push_back(rang[0]);
    Rep(i, n - 1) {
        pair<int, int> prev = ans[ans.size() - 1];
        pair<int, int> cur = rang[i];

        if (cur.second < prev.second) {
            continue;
        }
        if (prev.second < cur.first) {
            ans.push_back(cur);
        }
        if (cur.first <= prev.second && prev.second <= cur.second) {
            ans.pop_back();
            ans.push_back({prev.first, cur.second});
        }
    }
    for (pair<int, int> a : ans) {
        cout << a.first << " " << a.second << endl;
    }

    return 0;
}
