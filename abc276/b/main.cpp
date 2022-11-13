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
    int n, m;
    cin >> n >> m;
    vector<set<int>> cities(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b, a--, b--;
        cities[a].insert(b);
        cities[b].insert(a);
    }
    for (const set<int> se : cities) {
        cout << se.size() << " ";
        for (const int s : se) cout << s + 1 << " ";
        cout << endl;
    }
    return 0;
}
