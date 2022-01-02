#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
string s;
int main(){
    cin >> s;
    set<char> se;
    rep(i, s.length()) se.insert(s[i]);
    
    if(se.size() == 3) {
        cout << 6 << endl;
        return 0;
    }
    if(se.size() == 2) {
        cout << 3 << endl;
        return 0;
    }
    cout << 1 << endl;
    return 0;
}
