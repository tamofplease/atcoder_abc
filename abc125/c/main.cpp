// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

vector<int> listPrimes(int n) {
    vector<int> res;
    for (int i=1; i * i <= n ; i++) {
        if (n % i == 0) {
            res.push_back(i);
            res.push_back(n / i);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ref : a) {
        cin >> ref;
    }
    if (n == 2) {
        cout << max(a[0], a[1]) << endl;
        return 0;
    }
    map<int, int> ma;
    for (int i = 0 ; i < 3 ; i++) {
        vector<int> primes = listPrimes(a[i]);
        for (int aa : primes) {
           ma[aa]++;
       }
    }
    vector<int> rec;
    for (auto it : ma) {
        if (it.second > 1) {
            rec.push_back(it.first);
        }
    }

    for (int i = 3 ; i < n ; i++) {
        for (int d : rec) {
            if (a[i] % d == 0) ma[d]++;
        }
    }

    int ans = 0;
    for (auto it : ma) {
        if (it.second >= n - 1) {
            ans = max(ans, it.first);
        }
    }
    cout << ans << endl;

    return 0;
}
