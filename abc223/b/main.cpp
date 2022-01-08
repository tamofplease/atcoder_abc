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
    string s; cin >> s;
    int sl = s.length();
    string ma = s, mi = s;
    rep(i, sl) {
        s = s.substr(1, sl-1) + s[0];
        ma = max(ma, s); mi = min(mi, s);
    }
    cout << mi << endl;
    cout << ma << endl;
    return 0;
}
