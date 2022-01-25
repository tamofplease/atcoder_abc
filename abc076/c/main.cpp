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
    string s, t; cin >> s >> t;
    for(int i=s.length()-t.length()+1;i>=0;;i--) 
    rep(i, s.length()-t.length()+1) {
        bool isValid = true;
        rep(j, t.length()){
            if(s[i+j] != t[j] && s[i+j] != '?') {
                isValid = false;
            }
        }
        if(isValid) {
            rep(j, (int)s.length()) {
                if(i==j) {
                    rep(k, (int)t.length()) {
                        cout << t[k];
                    }
                    j += (int)t.length();
                }
                if(s[j] == '?') cout << 'a';
                else cout << s[j];
            }
            cout << endl;
            return 0;
        }
    }
    puts("UNRESTORABLE");
    return 0;
}
