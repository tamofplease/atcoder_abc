#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int main(){
    int n, k;cin >> n >> k;
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    map<int, int> ma;
    rep(i, k) {
        ma[c[i]]++;
    }
    int ans = ma.size();
    for(int i = k; i < n; i++ ) {
        int j = i - k;
        ma[c[j]]--;
        ma[c[i]]++;
        if(ma[c[j]] == 0) ma.erase(c[j]);
        int num = ma.size();
        ans = max(ans, num);
    }
    cout << ans << endl;
    return 0;
}
