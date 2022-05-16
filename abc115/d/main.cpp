// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t
map<int, ll> memo;
ll countPatty(int n) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    memo[n] = countPatty(n-1) * 2 + 1;
    return memo[n];
}

map<int, ll> memo_all;

ll countAll(int n) {
    if (memo_all.find(n) != memo_all.end()) {
        return memo_all[n];
    }
    memo_all[n] = countAll(n-1) * 2 + 3;
    return memo_all[n];
}

int main() {
    memo[0] = 1;
    memo_all[0] = 1;
    int n;
    ll x;
    cin >> n >> x;
    countAll(n);
    countPatty(n);

    auto search = [&] (auto f, ll cur, int layer) -> ll {
        if (cur < 2) {
            return 0;
        }
        cur--;
        if (cur < memo_all[layer-1]) {
            return f(f, cur, layer-1);
        }
        if (cur == memo_all[layer-1]) {
            return memo[layer-1];
        }
        if (cur == memo_all[layer-1] + 1) {
            return memo[layer-1] + 1;
        }
        if (cur < memo_all[layer-1] * 2) {
            return memo[layer-1] + 1 + f(f, cur-memo_all[layer-1]-1, layer-1);
        }
        return memo[layer-1] * 2 + 1;
    };

    cout << search(search, x, n) << endl;
    return 0;
}
