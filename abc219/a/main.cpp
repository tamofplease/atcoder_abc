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
    int x; cin >> x;
    if(x >= 90) puts("expert");
    else if (x >= 70) cout << 90 - x << endl;
    else if (x >= 40) cout << 70 - x << endl;
    else cout << 40 - x << endl;
    return 0;
}
