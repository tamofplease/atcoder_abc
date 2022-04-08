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
    if(x<100) {
        puts("No");
        return 0;
    }
    (x%100) ? puts("No") : puts("Yes");
    return 0;
}
