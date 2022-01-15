#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    rep(i, n) {
        set<char> front, back;
        rep(j, i) {
            front.insert(s[j]);
        }
        for(int j=i;j<n;j++) {
            back.insert(s[j]);
        }
        set<int> res;
        set_intersection(front.begin(), front.end(), back.begin(), back.end(), inserter(res, res.end()));
        ans = max(ans, (int)res.size());
    }
    cout << ans << endl;
    return 0;
}
