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

ll calc_opp_dist(ll left, ll center, ll right) { return right - left + min(right - center, center - left); }

ll calc_left_dist(ll left1, ll left2, ll center) { return center - min(left1, left2); }

ll calc_right_dist(ll right1, ll right2, ll center) { return max(right1, right2) - center; }

int main() {
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a), t(b), x(q);
    for (ll& ref : s) cin >> ref;
    for (ll& ref : t) cin >> ref;
    for (ll& ref : x) cin >> ref;

    for (ll xx : x) {
        int s_right_idx = lower_bound(ALL(s), xx) - s.begin();
        int t_right_idx = lower_bound(ALL(t), xx) - t.begin();
        int s_left_idx = s_right_idx - 1, t_left_idx = t_right_idx - 1;
        if (s_right_idx == a) {
            // s_left < xx;
            if (t_right_idx == b) {
                cout << calc_left_dist(s[s_left_idx], t[t_left_idx], xx) << endl;
                continue;
            }
            if (t_left_idx == -1) {
                cout <<
            }
        }
        if (s_right_idx == a && t_right_idx == b) {
            continue;
        }
        if (s_left_idx < 0 && t_left_idx < 0) {
            cout << calc_right_dist(s[s_right_idx], t[t_right_idx], xx) << endl;
            continue;
        }
        if (s_right_idx == a && t_left_idx < 0) {
            cout << calc_opp_dist(s[s_left_idx]) cout
                 << min(t[t_right_idx] - xx, xx - s[s_left_idx]) + t[t_right_idx] - s[s_left_idx] << endl;
            continue;
        }
        if (t_right_idx == b && s_left_idx < 0) {
            cout << min(s[s_right_idx] - xx, xx - t[t_left_idx]) + s[s_right_idx] - t[t_left_idx] << endl;
            continue;
        }
        if (s_right_idx == a) {
        }

        ll ans = min(max(s[s_right_idx], t[t_right_idx]) - xx, xx - min(s[s_left_idx], t[t_left_idx]));
        ans = min(ans, min(s[s_right_idx] - xx, xx - t[t_left_idx]) + s[s_right_idx] - t[t_left_idx]);
        ans = min(ans, min(t[t_right_idx] - xx, xx - s[s_left_idx]) + t[t_right_idx] - s[s_left_idx]);

        cout << ans << endl;
    }

    return 0;
}
