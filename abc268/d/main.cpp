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
    vector<string> s(n), t(m);
    for (string& ref : s) cin >> ref;
    for (string& ref : t) cin >> ref;

    unordered_map<string, int> ma;
    rep(i, n) ma[s[i]] = i;

    function<string(vector<int>)> to_string = [&](const vector<int> v) -> string {
        const int vv = v.size();
        string z = "";
        rep(i, vv) {
            if (i % 2) {
                rep(j, v[i]) z.push_back('_');
            } else {
                z += s[v[i]];
            }
        }
        return z;
    };

    unordered_set<string> se;
    for (string tt : t) se.insert(tt);

    string ans = "";
    vector<int> base, cur;
    auto rec = [&](auto f, int idx, int remain) -> void {
        if (ans.size()) return;
        if (idx + 1 == n) {
            cur.push_back(base[idx]);
            string res = to_string(cur);
            if (!se.count(res)) {
                if (3 <= res.length() && res.length() <= 16) {
                    ans = res;
                    return;
                }
            }
            cur.pop_back();
            return;
        }
        cur.push_back(base[idx]);
        cur.push_back(1);
        for (int i = 0; i <= remain; i++) {
            f(f, idx + 1, remain - i);
            cur.back()++;
        }
        cur.pop_back();
        cur.pop_back();
    };

    rep(i, n) base.push_back(i);
    int remain = 16 - n + 1;
    for (string ss : s) remain -= ss.length();

    do {
        if (ans.size()) break;
        vector<int> cur;
        rec(rec, 0, remain);
    } while (next_permutation(base.begin(), base.end()));

    if (ans.size())
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}