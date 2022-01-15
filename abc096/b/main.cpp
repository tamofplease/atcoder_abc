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
    int a, b, c; cin >> a >> b >> c;
    int k; cin >> k;
    int ma = max(a, max(b, c));
    int sum = a + b + c - ma;
    rep(i,k) {
        ma *= 2;
    }
    cout << ma + sum << endl;
    
    return 0;
}
