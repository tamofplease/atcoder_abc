// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

#define ll int64_t

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k), l(q);
    vector<bool> board(n, false);
    rep(i, k) {
        int a;
        cin >> a;
        board[a - 1] = true;
    }
    rep(i, q) {
        int l;
        cin >> l;
        int cnt = 0;
        rep(j, n - 1) {
            if (board[j]) {
                cnt++;
            }
            if (cnt == l) {
                if (board[j + 1]) {
                    break;
                }
                board[j] = false;
                board[j + 1] = true;
                break;
            }
        }
    }
    rep(i, n) {
        if (board[i])
            cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
}
