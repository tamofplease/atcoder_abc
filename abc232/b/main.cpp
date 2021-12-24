#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
string s, t;
int main(){
    cin >> s >> t;
    int st, tt;
    rep(i, s.length()-1) {
        st = (s[i] - s[i+1] + 26) % 26;
        tt = (t[i] - t[i+1] + 26) % 26;
        if(st != tt) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
