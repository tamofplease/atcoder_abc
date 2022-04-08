#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int l, r; cin >> l >> r;
    l--; r--;
    string s; cin >> s;
    rep(i, l) {
        cout << s[i];
    }
    for(int i = r; i >= l ; i--) {
        cout << s[i];
    }
    for(int i = r+1; i < s.length() ; i++) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}
