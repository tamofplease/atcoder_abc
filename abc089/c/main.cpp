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
    vector<string> s(n);
    map<char, int> ma;
    string target = "MARCH";
    rep(i, n) {
        string s; cin >> s;
        bool contain = false;
        for(char c : target) {
            if(c == s[0]) contain = true;
        }
        if(contain) ma[s[0]]++;
    }
    ll ans = 0;
    rep(i, 5) {
        rep(j, i) {
            rep(k, j) {
                ans += (ll)ma[target[i]] * ma[target[j]] * ma[target[k]];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
