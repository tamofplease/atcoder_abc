// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

const int MOD = 1000000007;

string tobin(ll n) {
    if (n < 2) {
        return to_string(n);
    }
    return tobin(n / 2) + to_string(n % 2);
}

ll toRLL(string s) {
    ll res = 0, tmp = 1;
    for (char c : s) {
        res += tmp * (c - '0');
        tmp *= 2;
    }
    return res;
}

int main() {
    ll n, c;
    cin >> n >> c;
    vector<pair<ll, ll>> digit(31, {0, 1});
    rep(i, n) {
        ll t, a;
        cin >> t >> a;
        string s = tobin(a);
        int sn = s.length();
        reverse(ALL(s));
        if (t == 1) {
            rep(j, 31) {
                digit[j].first = (j < sn ? digit[j].first & s[j] - '0' : 0);
                digit[j].second = (j < sn ? digit[j].second & s[j] - '0' : 0);
            }
        }
        if (t == 2) {
            rep(j, 31) {
                digit[j].first = (j < sn ? digit[j].first | s[j] - '0' : digit[j].first);
                digit[j].second = (j < sn ? digit[j].second | s[j] - '0' : digit[j].second);
            }
        }
        if (t == 3) {
            rep(j, 31) {
                digit[j].first ^= (j < sn ? s[j] - '0' : 0);
                digit[j].second ^= (j < sn ? s[j] - '0' : 0);
            }
        }
        string ss = tobin(c);
        reverse(ALL(ss));
        ll tmp = 1;
        c = 0;
        rep(j, 31) {
            c += tmp * (j < (int)ss.length() && ss[j] == '1' ? digit[j].second : digit[j].first);
            tmp *= 2;
        }
        cout << c << endl;
    }
    return 0;
}
