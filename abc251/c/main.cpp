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
    int n;
    cin >> n;
    set<string> used;
    map<string, int> score;
    int maxScore = -1;
    int ans;
    rep(i, n) {
        string s;
        cin >> s;
        int t;
        cin >> t;
        if (used.find(s) == used.end()) {
            used.insert(s);
            if (maxScore < t) {
                maxScore = t;
                ans = i;
            }
        }
    }
    cout << ans + 1 << endl;
    return 0;
}