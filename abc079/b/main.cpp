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
    int n; cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    ll prev = 1;
    ll prev_prev = 2;
    ll cur = 0;
    for(int i=2;i<=n;i++) {
        cur=prev+prev_prev;
        prev_prev = prev;
        prev = cur;
    }
    cout << cur << endl;
    return 0;
}
