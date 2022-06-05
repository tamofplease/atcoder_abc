// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

#define ll int64_t

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};

using Vote = std::pair<ll, ll>;
using Unordered_map = std::unordered_map<Vote, int, pair_hash>;

using P = pair<ll, ll>;
using prime_store_t = int;
using prime_vector = vector<int>;
ll ans = 0;
void dfs(ll a, ll b, const int n, const ll border, const vector<int> &divisor) {
    ans += 2;
    cout << a << " " << b << endl;
    ll ab = a * b;
    for (ll d : divisor) {
        ll dd = d * d;
        ll ad = a * d;
        ll add = a * dd;
        ll bdd = b * dd;
        ll bd = b * d;
        if (ab * dd <= border) {
            if (ad <= n && bd <= n && ad > bd) {
                dfs(ad, bd, n, border, divisor);
            }
            if (add <= n) {
                dfs(add, b, n, border, divisor);
            }
            if (bdd <= n && a > bdd) {
                dfs(a, bdd, n, border, divisor);
            }
        } else {
            return;
        }
    }
}

prime_vector forno_method(const prime_store_t limit) {
    prime_vector prime_num;
    std::valarray<bool> prims(true, limit + 1); // array of [0] to [limit]
    prims[std::slice(0, 2, 1)] = false; // 0 and 1 aren't primes. (not needed)

    const prime_store_t search_limit{
        static_cast<prime_store_t>(
            std::floor(std::sqrt(static_cast<long double>(limit)))) +
        1};
    for (prime_store_t i{2}; i < search_limit; ++i)
        if (prims[i]) {
            prims[std::slice(i * i, limit / i - (i - 1), i)] = false;
        }
    for (prime_store_t i{2}; i <= limit; ++i)
        if (prims[i])
            prime_num.push_back(i);
    return prime_num;
}

int main() {
    ll n;
    cin >> n;
    vector<int> primes = forno_method(n);

    dfs(1, 1, n, n * n, primes);
    cout << ans + n - 2 << endl;
    return 0;
}
