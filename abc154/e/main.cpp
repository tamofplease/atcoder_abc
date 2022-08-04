// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    string n;
    int k;
    cin >> n >> k;
    map<pair<string, int>, int> memo;
    // a = 10m * r;
    auto recur = [&](auto f, string N, int K) -> int {
        if (memo.find({N, K}) != memo.end()) return memo[{N, K}];
        if (K == 0) {
            return 0;
        }
        string nxt = N.substr(0, N.length() - 1);
        memo[{nxt, K - 1}] = f(nxt, K - 1);
        nxt memo[{}](N[N.length() - 1] - '0') * memo[{nxt, K - 1}];
    };

    return 0;
}