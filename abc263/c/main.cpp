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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans;
    vector<int> pick;
    Rep(i, m) pick.push_back(i);
    vector<int> now;
    auto recur = [&](auto f, int cur) -> void {
        if (now.size() == n) {
            ans.push_back(now);
            return;
        }
        for (int i = cur; i < m; i++) {
            now.push_back(pick[i]);
            f(f, i + 1);
            now.pop_back();
        }
    };
    recur(recur, 0);
    for (const vector<int> aa : ans) {
        for (int a : aa) {
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}
