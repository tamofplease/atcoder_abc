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
    ll k; cin >> k;
    if(s[0] == '1') {
        if(k == 1) cout << 1 << endl;
        else {
            Rep(i, k-1) {
                if(s[i] != '1') {
                    cout << s[i] << endl;
                    return 0;
                }
            }
            cout << 1 << endl;
        }
    } else {
        cout << s[0] - '0' << endl;
    }
    return 0;
}
