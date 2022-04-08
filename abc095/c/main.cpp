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
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    int ans = INT32_MAX;
    for(int mix=0; mix<=(max(x, y) * 2); mix+=2) {
        int remain_x = max(0, x - mix/2);
        int remain_y = max(0, y - mix/2);
        int x_price = remain_x * a;
        int y_price = remain_y * b;
        int mix_price = mix * c;
        ans = min(ans, x_price + y_price + mix_price);
    }
    cout << ans << endl;
    return 0;
}
