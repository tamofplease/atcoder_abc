#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a,b,c,d; cin >> a >> b >> c >> d;
    const string takahashi = "Takahashi";
    const string aoki = "Aoki";
    if(a < c) {
        cout << takahashi << endl;
        return 0;
    }
    if(a > c) {
        cout << aoki << endl;
        return 0;
    }
    if(b <= d) {
        cout << takahashi << endl;
    } else {
        cout << aoki << endl;
    }
    
    return 0;
}