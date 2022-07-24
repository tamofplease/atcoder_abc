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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ref : a) cin >> ref;
    multiset<int> hold;
    for (int aa : a) {
        auto it = hold.lower_bound(aa);
        if (it != hold.begin()) {
            it--;
            hold.erase(it);
        }
        hold.insert(aa);
    }
    cout << (int)hold.size() << endl;
    return 0;
}
