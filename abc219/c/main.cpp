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
    string x; cin >> x;
    map<char, char> ma1, ma2;
    for(int i=97;i<=122;i++) {
        ma1[x[i-97]] = char(i);
        ma2[char(i)] = x[i-97];
    }

    int n; cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    rep(i, n) {
        rep(j, (int)s[i].length()) s[i][j] = ma1[s[i][j]];
    }
    sort(ALL(s));
    rep(i, n) {
        rep(j, (int)s[i].length()) s[i][j] = ma2[s[i][j]];
    }
    rep(i, n) {
        cout << s[i] << endl;
    }
    return 0;
}
