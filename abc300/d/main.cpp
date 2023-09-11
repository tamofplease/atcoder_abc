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
    ll n;
    cin >> n;
    int upper = 288676;
    vector<bool> isPrime(upper, true);
    isPrime[0] = false;
    isPrime[1] = false;
    vector<int> primes;
    rep(i, upper + 1) {
        if (!isPrime[i]) continue;
        isPrime[i] = true;
        primes.push_back(i);
        int j = i;
        while (j < upper + 2) {
            j += i;
            isPrime[j] = false;
        }
    }
    cout << primes.size() << endl;

    return 0;
}
