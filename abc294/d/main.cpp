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
    int n, q;
    cin >> n >> q;
    queue<int> que;
    set<int> called;
    for (int i = 0; i < n; i++) que.push(i);

    vector<int> ans;
    rep(i, q) {
        int type;
        cin >> type;
        if (type == 1) {
            int cur = que.front();
            que.pop();
            called.insert(cur);
            continue;
        }
        if (type == 2) {
            int x;
            cin >> x, x--;
            called.erase(x);
            continue;
        }
        if (type == 3) {
            int num = *(called.begin());
            ans.push_back(num + 1);
        }
    }
    for (int a : ans) cout << a << endl;
    return 0;
}
