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
    map<int, vector<int>> to;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    set<int> been;
    queue<int> q;
    q.push(1);
    been.insert(1);
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (int nxt : to[cur]) {
            if (been.count(nxt)) continue;
            been.insert(nxt);
            q.push(nxt);
        }
    }
    cout << *(been.rbegin()) << endl;

    return 0;
}
