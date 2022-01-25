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
    int sl = (int)s.length();
    int tl = (int)t.length();
    for(int i=sl-tl+1;i>=0;i--) {
        bool isValid=true;
        rep(j, tl) {
            if(s[i+j] != t[j] && s[i+j] != '?') {
                isValid=false;
            }
        }
        if(isValid) {
            rep(j, (int)sl) {
                if(i==j) {
                    rep(k, tl) {
                        cout << t[k];
                    }
                    j+=(int)tl;
                }
                if(s[j] == '?') cout << 'a';
                else if(j < sl) cout << s[j];
            }
            cout << endl;
            return 0;
        }
    }
    puts("UNRESTORABLE");
    return 0;
}
