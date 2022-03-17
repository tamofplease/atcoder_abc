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
    int a,b,c,x;cin >> a >> b >> c >> x;
    if(x <= a) cout << 1.0000000 << endl;
    else if(x > b) cout << 0.000000 << endl;
    else printf("%.10f\n", (double)c/(b-a));
    return 0;
}