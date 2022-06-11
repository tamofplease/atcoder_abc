// "Copyright 2022 tam"
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

#define ll int64_t

ll countSeven(ll x) {
    ll res = 0;
    Rep(i, x) {
        string s = to_string(i);
        for (char c : s) {
            if (c == '7') {
                res++;
                break;
            }
        }
    }
    return res;
}

int main() {
    ll a, b, n;
    cin >> a >> b >> n;

    auto isValid = [&](ll x) -> bool {
        return (b * countSeven(x) + a * (x + 1)) >= n;
    };
    ll invalid = -1, valid = n;
    while (valid - invalid > 1) {
        ll mid = (invalid + valid) / 2;
        if (isValid(mid)) {
            valid = mid;
        } else {
            invalid = mid;
        }
    }
    cout << valid << endl;

    return 0;
}
