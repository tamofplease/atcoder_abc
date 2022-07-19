// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

#define ll int64_t

int main() {
    ll n;
    cin >> n;
    vector<bool> isPrime(1000001, true);
    vector<int> primes;
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= 1000000; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            int j = i + i;
            while (j <= 1000000) {
                isPrime[j] = false;
                j += i;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < primes.size(); i++) {
        ll q = primes[i];
        q = q * q * q;
        ll tmp = n;
        tmp /= q;
        if (tmp < 2) {
            break;
        }
        if (tmp >= q) {
            tmp = q;
        }
        auto it = upper_bound(primes.begin(), primes.begin() + i, tmp) - 1;

        int res = it - primes.begin();
        ans += res + 1;
    }
    cout << ans << endl;
    return 0;
}
