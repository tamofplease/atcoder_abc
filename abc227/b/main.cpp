#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int n; cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];
    int ans = n;
    rep(i, n) {
        bool flag = false;
        Rep(a, 1000) Rep(b, 1000) {
            int tmp = 4 * a * b + 3 * (a + b);
            if(s[i] == tmp) {
                flag = true;
            }
        }
        if(flag) {
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}
