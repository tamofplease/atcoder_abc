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
    vector<int> a(3);
    rep(i, 3) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    rep(i, 2) {
        ans += abs(a[i] -a[i+1]);
    }
    cout << ans << endl;
    return 0;
}
