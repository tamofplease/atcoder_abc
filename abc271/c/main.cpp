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
    for (int& ref : a) cin >> ref;
    sort(ALL(a));
    auto ok = [&](int x) -> bool {
        unordered_set<int> se;
        for (const int aa : a)
            if (aa <= x) se.insert(aa);
        int s = (int)se.size();
        return s + (n - s) / 2 >= x;
    };
    int valid = -1, invalid = n + 1;
    while (invalid - valid > 1) {
        int mid = (invalid + valid) / 2;
        (ok(mid) ? valid : invalid) = mid;
    }
    cout << valid << endl;

    return 0;
}
