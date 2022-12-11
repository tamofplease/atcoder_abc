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
    int n;
    cin >> n;
    vector<bool> isPrime(100, true);
    vector<int> primes;
    isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        int j = i * 2;
        primes.push_back(i);
        while (j <= n) {
            isPrime[j] = false;
            j += i;
        }
    }
    map<int, int> primeCount;

    for (int i = 2; i <= n; i++) {
        int j = i;
        for (int prime : primes) {
            while (prime <= j && j % prime == 0) {
                j /= prime;
                primeCount[prime]++;
            }
        }
    }
    int four = 0, two = 0, t_f = 0, s_f = 0, f_t = 0;
    for (pair<int, int> p : primeCount) {
        if (p.second >= 74) s_f++;
        if (p.second >= 24) t_f++;
        if (p.second >= 14) f_t++;
        if (p.second >= 4) four++;
        if (p.second >= 2) two++;
    }

    int ans = four * (four - 1) * (two - 2) / 2;
    ans += s_f;
    ans += t_f * (two - 1);
    ans += f_t * (four - 1);
    cout << ans << endl;
    return 0;
}
