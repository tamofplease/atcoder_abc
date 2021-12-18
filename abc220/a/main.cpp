#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int a,b,c;cin >> a >> b >> c;
    int d = b / c * c;
    if (b < d || d < a) cout << -1 << endl;
    else cout << d << endl;

    return 0;
}
