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
    ll total = 0;
    int cur = 0;
    rep(i, n) {
        total += abs(cur - a[i]);
        cur = a[i];
    }
    total += abs(cur);
    cur = 0;
    rep(i, n-1) {
        int tmp = total - abs(cur-a[i]) - abs(a[i]-a[i+1]) + abs(cur-a[i+1]);
        cur = a[i];
        cout << tmp << endl;
    }
    cout << total - abs(a[n-2] - a[n-1]) - abs(a[n-1]) + abs(a[n-2]) << endl;

    return 0;
}
