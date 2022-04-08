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
    string s, t; cin >> s >> t;
    s += s;
    rep(i, t.length()) {
        string tmp = s.substr(i, t.length());
        if(tmp == t) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
