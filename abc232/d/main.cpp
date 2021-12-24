#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int route[110][110];
int H, W;
void show() {
    rep(i,H) {
        rep(j, W) {
            cout << route[i][j];
        }
        cout << endl;
    }
}

int main(){
    cin >> H >> W;
    char table[110][110];
    rep(i, H) rep(j, W) cin >> table[i][j];
    route[0][0] = 1;
    rep(i, H) rep(j, W) {
        if(route[i][j] == 0) {
            continue;
        }
        if(table[i+1][j] != '#' && i+1 < H) {
            route[i+1][j] = max(route[i+1][j], route[i][j]+1);
        }
        if(table[i][j+1] != '#' && j+1 < W) {
            route[i][j+1] = max(route[i][j+1], route[i][j]+1);
        }
    }
    // show();
    int ans = 0;
    rep(i, H) rep(j, W) {
        ans = max(ans, route[i][j]);
    }
    cout << ans << endl;
    return 0;
}
