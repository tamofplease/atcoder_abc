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
    int n, y; cin >> n >> y;
    y /= 1000;
    rep(i, 2001) rep(j, 2001) {
        int k = n - i - j;
        if(k>=0 && y == i * 10 + j * 5 + k) {
            cout << i << " " << j << " " << k << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}
