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
using mint = modint998244353;

int main() {
    int n;
    cin >> n;
    mint front = 1, back = 1;
    pair<int, int> prev;
    cin >> prev.first >> prev.second;
    rep(i, n - 1) {
        pair<int, int> cur;
        cin >> cur.first >> cur.second;
        mint nxt_front = 0, nxt_back = 0;
        if (cur.first != prev.first) nxt_front += front;
        if (cur.first != prev.second) nxt_front += back;
        if (cur.second != prev.first) nxt_back += front;
        if (cur.second != prev.second) nxt_back += back;
        front = nxt_front, back = nxt_back;
        prev = cur;
    }
    cout << (front + back).val() << endl;

    return 0;
}
