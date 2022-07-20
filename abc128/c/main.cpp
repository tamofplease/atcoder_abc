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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n);
    vector<int> k(m);
    rep(i, m) {
        cin >> k[i];
        vector<int> ss(k[i]);
        rep(j, k[i]) {
            cin >> ss[j];
        }
        s[i] = ss;
    }
    vector<int> p(m);
    rep(i, m) {
        cin >> p[i];
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        set<int> ons;
        for (int bit = 0; bit < n; bit++) {
            if (i & (1 << bit))
                ons.insert(bit + 1);
        }
        bool valid = true;
        rep(j, m) {
            vector<int> ss = s[j];
            int cnt = 0;
            for (int sss : ss)
                cnt += ons.find(sss) != ons.end();
            if (cnt % 2 != p[j]) {
                valid = false;
                break;
            }
        }
        ans += valid;
    }
    cout << ans << endl;
    return 0;
}
