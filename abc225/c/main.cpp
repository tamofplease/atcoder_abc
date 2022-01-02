#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> b(n);
    rep(i, n) {
        vector<int> c(m);
        rep(j, m) {
            cin >> c[j];
        }
        b[i] = c;
    }
    rep(i, n) {
        rep(j, m-1) {
            if(b[i][j] != b[i][j+1]-1) {
                puts("No");
                return 0;
            }
            if((b[i][j]-1) % 7 >= (b[i][j+1]-1) % 7) {
                puts("No");
                return 0;
            }
        }
    }
    rep(i, m) {
        rep(j, n-1) {
            if(b[j][i] != b[j+1][i] - 7) {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    return 0;
}
