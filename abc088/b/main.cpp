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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(ALL(a), greater<int>());
    int al=0, bb=0;
    rep(i, n) {
        if(i%2==0) al+=a[i];
        else bb+=a[i];
    }
    cout << al - bb << endl;
    return 0;
}
