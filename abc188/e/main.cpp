#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& ref : a) cin >> ref;
    vector<vector<int>> to(n);
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        to[x].push_back(y);
    }
    vector<bool> visited(n, false);
    int ans = INT32_MIN;

    auto recursion = [&](auto f, int cur, int from, int toward) -> void {
        // cout << cur << " " << from << " " << toward << endl;
        bool hasNext = false;
        visited[cur] = true;
        for (int nxt : to[cur]) {
            if (!visited[nxt]) {
                hasNext = true;
                f(f, nxt, min(a[nxt], from), max(a[nxt], toward));
            }
        }
        if (!hasNext && toward != -1) {
            ans = max(ans, toward - from);
        }
    };
    
    rep(i, n) {
        recursion(recursion, i, a[i], -1);
    }
    cout << ans << endl;
    return 0;
}