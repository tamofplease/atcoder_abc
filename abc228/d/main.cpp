#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int q; cin >> q;
    int n  = 1 << 20;
    set<int> s;
    vector<ll> val(n, -1);
    rep(i, n) s.insert(i);
    rep(i, q) {
        ll type, x; cin >> type >> x;
        if (type == 1) {
            auto iter = s.lower_bound(x%n);
            if(iter == s.end()) {
                iter = s.begin();
            }
            val[*iter] = x;
            s.erase(*iter);
        } else {
            cout << val[x%n] << endl;
        }
    }
    
    return 0;
}
