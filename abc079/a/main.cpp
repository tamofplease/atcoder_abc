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
    string n; cin >> n;
    if(count(n.begin(), n.end()-1, n[0]) == 3 || count(n.begin()+1, n.end(), n[1]) == 3) puts("Yes");
    else puts("No");
    return 0;
}
