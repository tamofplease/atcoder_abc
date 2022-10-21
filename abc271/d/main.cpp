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
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    string ans;
    set<pair<int, int>> memo;
    auto ref = [&](auto f, int idx, int cur) -> void {
        if (cur > s || memo.count({idx, cur})) return;
        if (idx + 1 == n) {
            if (cur + a[idx] == s)
                ans.push_back('H');
            else if (cur + b[idx] == s)
                ans.push_back('T');
            return;
        }
        f(f, idx + 1, cur + a[idx]);
        if (ans.length()) {
            ans.push_back('H');
            return;
        }
        f(f, idx + 1, cur + b[idx]);
        if (ans.length()) {
            ans.push_back('T');
            return;
        }
        memo.emplace(idx, cur);
    };

    ref(ref, 0, 0);
    if (!ans.length()) {
        puts("No");
        return 0;
    }
    puts("Yes");
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}
