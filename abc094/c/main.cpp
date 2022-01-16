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
    vector<int> x(n), y(n);
    rep(i, n) {
        cin >> x[i];
        y[i] = x[i];
    }
    sort(ALL(y));
    int smallMid = y[(n-1)/2];
    int largeMid = y[(n+1)/2];
    double mid = double(smallMid + largeMid) / 2;
    rep(i, n) {
        if(x[i] >= mid) {
            cout << smallMid << endl;
        } else {
            cout << largeMid << endl;
        }
    }
    return 0;
}
