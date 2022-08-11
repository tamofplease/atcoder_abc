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
    int n, q;
    cin >> n >> q;
    // 園児ID: {所属ID、レート}
    unordered_map<int, pair<int, int>> in;

    // 幼稚園ID: {{レート, 園児ID1}, {レート, 園児ID2}}
    map<int, set<pair<int, int>>> elem;

    rep(i, n) {
        int a, b;
        cin >> a >> b;
        in[i] = {b, a};
        elem[b].emplace(a, i);
    }

    // {{レート, 幼稚園ID}}
    set<pair<int, int>> top;
    for (auto it : elem) {
        int rate = (*it.second.rbegin()).first;
        top.emplace(rate, it.first);
    }
    rep(i, q) {
        int infantId, to;
        cin >> infantId >> to, infantId--;
        auto [from, rate] = in[infantId];

        // 削除
        elem[from].erase({rate, infantId});
        if (!elem[from].size()) elem.erase(from);
        if (top.find({rate, from}) != top.end()) {
            top.erase({rate, from});
            if (!elem.size()) {
                top.emplace((*elem[from].rbegin()).first, from);
            }
        }

        // 登録
        if (elem.find(to) != elem.end()) {
            top.erase({(*elem[to].rbegin()).first, to});
        }
        elem[to].emplace(rate, infantId);
        top.emplace((*elem[to].rbegin()).first, to);
        in[infantId].first = to;

        std::cout << (*(top.begin())).first << endl;
    }

    return 0;
}
