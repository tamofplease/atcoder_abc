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
    ll x_1, y_1, x_2, y_2;
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    int d[4] = {1,2,-1,-2};
    for(int i=0;i<4;i++) for(int j=0;j<4;j++) {
        int dx=d[i], dy=d[j];
        if(dx == dy || dx == -dy) continue;
        int tx = x_1 + dx, ty = y_1 + dy;
        if((x_2-tx)*(x_2-tx) == 5 - (y_2-ty) * (y_2-ty)) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
