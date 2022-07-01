// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> w(n);
    for (auto &ref : w)
        cin >> ref;
    vector<int> children, adults;
    rep(i, n) { (s[i] == '1' ? adults : children).push_back(w[i]); }
    if (adults.size() == 0 || children.size() == 0) {
        cout << max(adults.size(), children.size()) << endl;
        return 0;
    }
    sort(ALL(adults));
    sort(ALL(children));
    int m = children.size();
    int ans = max(adults.size(), children.size());
    // 30 60 80
    // 40 45
    ///
    /// 39 40 41
    /// 40

    rep(i, m) {
        int cur = children[i] + 1;
        int tgtANum =
            adults.size() - (lower_bound(ALL(adults), cur) - adults.begin());
        ans = max(ans, i + 1 + tgtANum);
    }

    cout << ans << endl;

    return 0;
}
