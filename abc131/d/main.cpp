// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define Rep(i, n) for (int i = 1 ; i <= n ; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    rep(i, n) {
        cin >> ab[i].second >> ab[i].first;
    }
    sort(ALL(ab));
    int cur = 0;
    for (pair<int, int> p : ab) {
        cur += p.second;
        if (cur > p.first) {
            puts("No");
            return 0;
        }
    }

    puts("Yes");

    return 0;
}
