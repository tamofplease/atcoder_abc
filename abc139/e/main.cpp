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
    vector<queue<int>> q(n);
    rep(i, n) {
        rep(j, n - 1) {
            int a;
            cin >> a, a--;
            q[i].push(a);
        }
    }
    int ans = 0;
    int emp = n;
    while (emp > 0) {
        vector<int> hold;
        rep(cur, n) {
            if (q[cur].empty()) {
                continue;
            }
            int nxt = q[cur].front();
            if (nxt < cur) continue;
            if (q[nxt].front() == cur) {
                hold.push_back(cur);
                hold.push_back(nxt);
            }
        }
        if (hold.size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        for (int h : hold) {
            q[h].pop();
            if (q[h].empty()) emp--;
        }
        ans++;
    }
    cout << ans << endl;

    return 0;
}
