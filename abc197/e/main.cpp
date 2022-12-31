// "Copyright 2022 tam"
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define Rep(i, n) for (ll i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<ll, ll>;

const ll MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    map<int, vector<int>> ma;
    rep(i, n) {
        int x, c;
        cin >> x >> c;
        if (!ma.count(c)) {
            ma[c].push_back(x);
        }
        ma[c].push_back(x);
        sort(ALL(ma[c]));
        if (ma[c].size() > 2) {
            ma[c].erase(next(ma[c].begin()));
        }
    }
    ma[-1] = {0, 0};
    map<int, vector<ll>> memo;
    memo[-1] = {0, 0};
    int prev_color = -1;
    ll ans = INT64_MAX;
    for (auto [cur_color, idx] : ma) {
        const ll left_idx = idx[0], right_idx = idx[1];
        const ll prev_left_idx = ma[prev_color][0], prev_right_idx = ma[prev_color][1];
        const ll prev_left_cost = memo[prev_color][0], prev_right_cost = memo[prev_color][1];
        memo[cur_color] = {
            min(prev_left_cost + abs(prev_left_idx - right_idx), prev_right_cost + abs(prev_right_idx - right_idx)),
            min(prev_left_cost + abs(prev_left_idx - left_idx), prev_right_cost + abs(prev_right_idx - left_idx)),
        };
        memo[cur_color][0] += abs(right_idx - left_idx);
        memo[cur_color][1] += abs(right_idx - left_idx);
        prev_color = cur_color;
        ans = min(memo[cur_color][0] + abs(left_idx), memo[cur_color][1] + abs(right_idx));
    }

    cout << ans << endl;

    return 0;
}
