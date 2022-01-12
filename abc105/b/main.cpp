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
    int n; cin >> n;
    rep(i, 100) rep(j, 100) {
        if(i*4+j*7 == n) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
