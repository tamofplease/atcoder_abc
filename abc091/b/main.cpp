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
    map<string, int> ma;
    int n; cin >> n;
    rep(i, n) {
        string s; cin >> s;
        if(ma.find(s) != ma.end()) ma[s]++;
        else ma[s] = 1;
    }
    int m; cin >> m;
    rep(i, m) {
        string s; cin >> s;
        if(ma.find(s) != ma.end()) ma[s]--;
        else ma[s] = -1;
    }
    int ans = 0;
    string s;
    for(auto const& [key, value] : ma)  {
        if(value > ans) {
            s = key;
            ans = value;
        }
    }
    cout << ans << endl;
    return 0;
}
