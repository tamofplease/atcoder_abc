#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &ref : a) cin >> ref;
    int hold[1500001];
    memset(hold, 0, sizeof(hold));
    rep(i, m) hold[a[i]]++;
    int ans = 0;
    while (hold[ans] != 0) {
        ans++;
    }
    rep(i, n - m) {
        hold[a[i + m]]++;
        if (--hold[a[i]] == 0) {
            ans = min(ans, i);
        }
    }

    cout << ans << endl;
    return 0;
}