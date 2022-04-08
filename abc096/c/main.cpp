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
    int h, w; cin >> h >> w;
    vector<string> table;
    rep(i, h) {
        string s; cin >> s;
        table.push_back(s);
    }
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,-1,1};
    rep(i, h) rep(j, w) {
        if(table[i][j] == '#') {
            bool isValid = false;
            rep(k, 4) {
                int dx = x[k], dy = y[k];
                int cx = dx + j, cy = dy + i;
                if(0 <= cx && cx < w && 0 <= cy && cy < h) {
                    if(table[cy][cx] == '#') {
                        isValid = true;
                    }
                }

            }
            if(!isValid) {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    return 0;
}
