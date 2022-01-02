#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int h, w; cin >> h >> w;
    vector<vector<int>> a(h);
    rep(i, h) {
        vector<int> b(w);
        rep(j, w) {
            cin >> b[j];
        }
        a[i] = b;
    }
    rep(i_2, h) {
        rep(i_1, i_2) {
            rep(j_2, w) {
                rep(j_1, j_2) {
                    if(a[i_1][j_1] + a[i_2][j_2] > a[i_2][j_1] + a[i_1][j_2]) {
                        puts("No");
                        return 0;
                    }
                }
            }
        }
    }
    puts("Yes");
    return 0;
}
