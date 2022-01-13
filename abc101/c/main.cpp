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
    int n,k; cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = 1;
    int tmp = k;
    while(tmp < n) {
        tmp += k;
        tmp--;
        ans++;
    }
    cout<< ans << endl;
    return 0;
}
