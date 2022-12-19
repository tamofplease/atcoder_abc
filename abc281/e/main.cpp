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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int& ref : a) cin >> ref;
    map<int, int> include, exclude;
    vector<int> tmp;
    rep(i, m) tmp.push_back(a[i]);
    sort(ALL(tmp));
    ll ans = 0, cnt = k;
    rep(i, k) {
        include[tmp[i]]++;
        ans += tmp[i];
    }
    for (int i = k; i < m; i++) exclude[tmp[i]]++;

    cout << ans << " ";
    for (int i = 0; i < n - m; i++) {
        // for (pair<int, int> ex : exclude) cout << ex.first << ": " << ex.second << endl;
        // cout << endl;
        int out = a[i], in = a[i + m];
        bool shortage = false;
        if (exclude.count(out)) {
            exclude[out]--;
            if (exclude[out] == 0) exclude.erase(out);
        } else {
            include[out]--;
            if (include[out] == 0) include.erase(out);
            shortage = true;
            ans -= out;
        }
        exclude[in]++;
        if (shortage) {
            int exclude_min = (*exclude.begin()).first;
            exclude[exclude_min]--;
            if (exclude[exclude_min] == 0) exclude.erase(exclude_min);
            include[exclude_min]++;
            ans += exclude_min;
        }
        if (include.size() && exclude.size()) {
            int exclude_min = (*exclude.begin()).first;
            int include_max = (*include.rbegin()).first;
            if (exclude_min < include_max) {
                exclude[exclude_min]--;
                if (exclude[exclude_min] == 0) exclude.erase(exclude_min);
                include[include_max]--;
                if (include[include_max] == 0) include.erase(include_max);
                exclude[include_max]++;
                include[exclude_min]++;
                ans += (exclude_min - include_max);
            }
        }
        cout << ans;
        if (i != n - m - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
