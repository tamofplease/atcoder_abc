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
    set<int> se;
    bool isFinish = false;
    auto buf_input = [&]() -> void {
        if (isFinish) return;
        string k;
        cin >> k;
        int ik = -1;
        if (k != "OK") ik = stoi(k);
        if (ik == -1) isFinish = true;
        if (isFinish) return;
        rep(i, ik) {
            int v;
            cin >> v;
        }
    };
    auto dfs = [&](auto f, int cur) -> void {
        string k;
        cin >> k;
        int ik = -1;
        if (k != "OK") ik = stoi(k);
        if (ik == -1) isFinish = true;
        if (isFinish) return;

        vector<int> v(ik);
        rep(i, ik) { cin >> v[i], v[i]--; }

        for (int i = ik - 1; i >= 0; i--) {
            if (!se.count(v[i])) {
                se.insert(v[i]);
                if (isFinish) return;
                cout << v[i] + 1 << endl;
                f(f, v[i]);
                se.erase(v[i]);
                if (isFinish) return;
                cout << cur + 1 << endl;
                buf_input();
            }
        }
        return;
    };

    se.insert(0);
    dfs(dfs, 0);

    return 0;
}
