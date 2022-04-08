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
    int n, x; cin >> n >> x;
    vector<int> m(n);
    int all = 0;
    int mi = INT32_MAX;
    rep(i, n) {
        cin >> m[i];
        all += m[i];
        mi = min(m[i], mi);
    }
    x-=all;
    cout << n + (x/mi) << endl;

    return 0;
}
