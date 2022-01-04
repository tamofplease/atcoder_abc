#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    string s, t; cin >> s >> t;
    int sl = s.length();
    if(s.length() != t.length()) {
        puts("No");
        return 0;
    }
    rep(i, sl) {
        if(s[i] != t[i]) {
            if(s[i] == t[i+1] && s[i+1] == t[i]) {
                puts("Yes");
            } else {
                puts("No");
            }
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
