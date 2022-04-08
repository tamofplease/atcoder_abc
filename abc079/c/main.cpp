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
    string s; cin >> s;
    rep(i, 8) {
        int tmp  = s[0] - '0';
        int b = s[1] - '0';
        int c = s[2] - '0';
        int d = s[3] - '0';
        tmp = (i&1) ? tmp + b : tmp - b;
        tmp = (i&2) ? tmp + c : tmp - c;
        tmp = (i&4) ? tmp + d : tmp - d;
        if(tmp == 7) {
            cout << s[0] << ((i&1) ? '+' : '-' )<< s[1] << ((i&2) ? '+' : '-') << s[2] << ((i&4) ? '+' : '-') << s[3] << '=' << '7' << endl;
            return 0;
        }
    }
    return 0;
}
