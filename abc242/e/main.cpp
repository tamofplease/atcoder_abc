#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 998244353;

///  O(N*T) < 10^6
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(i, t) {
        int n;
        string s;
        cin >> n >> s;
        ll sm = 0;
        rep(i, (n + 1) / 2) {
            sm *= 26;
            sm += (s[i] - 'A');
            sm %= MOD;
        }
        string res = "", cur = "";
        rep(i, n / 2) cur.push_back(s[i]);
        res += cur;
        if (n % 2) res.push_back(s[n / 2]);
        reverse(cur.begin(), cur.end());
        res += cur;
        if (res <= s) sm += 1;
        cout << sm % MOD << endl;
    }
    return 0;
}