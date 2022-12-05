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

bool IsPrime(ll num) {
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

vector<pair<ll, ll>> prime_factorize(ll N) {
    vector<pair<ll, ll>> res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0;  // 指数

        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        res.push_back({a, ex});
    }

    if (N != 1) res.push_back({N, 1});
    return res;
}

ll firstGot(ll num, int times) {
    ll i = 0;
    while (times > 0) {
        i += num;
        ll tmp = i;
        while (tmp % num == 0) {
            tmp /= num;
            times--;
        }
    }
    return i;
}

int main() {
    ll k;
    cin >> k;

    if (IsPrime(k)) {
        cout << k << endl;
        return 0;
    }

    vector<pair<ll, ll>> divisor = prime_factorize(k);

    ll ans = 0;

    for (const pair<ll, ll> val : divisor) {
        ans = max(ans, firstGot(val.first, val.second));
    }

    cout << ans << endl;
    return 0;
}
