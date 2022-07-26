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

using P = pair<int, int>;
bool comp(const P& a, const P& b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> v;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    priority_queue<int> pq;
    ll ans = 0;
    Rep(i, m) {
        if (v.find(i) != v.end()) {
            for (int vv : v[i]) {
                pq.push(vv);
            }
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;

    return 0;
}
