#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int main(){
    int n,k,a;
    cin >> n >> k >> a;
    int cur = a - 1;
    k--;
    rep(i, k) {
        cur += 1;
        cur %= n;
    }
    cout << cur + 1 << endl;

    return 0;
}
