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
    const int n;
    cin >> n;
    vector<int> parent(n * 2 + 2, 0);
    parent[1] = 0;
    for (int i = 2; i <= 2 * n + 1; i += 2) {
        int a;
        cin >> a;
        parent[i] = parent[i + 1] = parent[a] + 1;
    }
    Rep(i, n * 2 + 1) cout << parent[i] << endl;
    return 0;
}
