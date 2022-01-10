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
    int n; cin >> n;
    vector<int> x(n), y(n), h(n);
    rep(i, n) {
        cin >> x[i] >> y[i] >> h[i];
    }
 
    rep(j, 101) rep(k, 101) {
        ll cur_h = -1;
        bool isValid = true;
        rep(i, n) {
            ll tm = h[i] + abs(x[i] - j) + abs(y[i] - k);
            if(h[i] == 0) continue;
            if(cur_h == -1) cur_h = tm;
            else if(cur_h != tm) {
                isValid = false;
                break;
            }
        }
        if(isValid) {
            rep(i, n) {
                if (h[i] != max((ll)0, cur_h - abs(x[i] - j) - abs(y[i] - k))) {
                    isValid = false;
                    break;
                }
            }
        }
        if(isValid) {
            cout << j << " " << k << " " << cur_h << endl;
            return 0;
        }
    }
 
    return 0;
}
