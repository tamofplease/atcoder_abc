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

int main() {
    ll a, b;
    cin >> a >> b;
    ll roop = max(a, b);
    vector<ll> ans;
    ans.push_back(1);
    ll i = 2;
    for (; i * i <= roop; i++) {
        if (a % i == 0 && b % i == 0) {
            ans.push_back(i);
        }
        while (a % i == 0) a /= i;
        while (b % i == 0) b /= i;
    }
    if (a == b && a != 1) {
        ans.push_back(a);
    }
    cout << ans.size() << endl;
    return 0;
}
