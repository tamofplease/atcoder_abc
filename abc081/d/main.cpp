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
    int ma = INT32_MIN, mi = INT32_MAX;
    int ma_idx = 0, mi_idx = 0;
    rep(i, n) {
        cin >> a[i];
        if (ma < a[i]) ma_idx = i;
        if (mi > a[i]) mi_idx = i;
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }
    vector<vector<int>> ans;
    function<void()> show = [&]() -> void {
        cout << ans.size() << endl;
        for (vector<int>& v : ans) cout << v[0] + 1 << " " << v[1] + 1 << endl;
    };
    if (mi >= 0) {
        for (int i = 0; i < n - 1; i++) ans.push_back({i, i + 1});
        show();
        return 0;
    }
    if (ma <= 0) {
        for (int i = n - 1; i >= 1; i--) ans.push_back({i, i - 1});
        show();
        return 0;
    }

    if (abs(ma) < abs(mi)) {
        for (int i = 0; i < n; i++) {
            ans.push_back({mi_idx, i});
        }
        for (int i = n - 1; i >= 1; i--) ans.push_back({i, i - 1});
        show();
        return 0;
    }
    for (int i = 0; i < n; i++) {
        ans.push_back({ma_idx, i});
    }
    for (int i = 0; i < n - 1; i++) ans.push_back({i, i + 1});
    show();
    return 0;
}
