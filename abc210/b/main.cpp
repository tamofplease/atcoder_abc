#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int n; string s;
    cin >> n >> s;
    rep(i, n) {
        if(s[i] == '1') {
            cout << ((i % 2 == 0) ? "Takahashi" : "Aoki") << endl;
            return 0;
        }
    }
    return 0;
}
