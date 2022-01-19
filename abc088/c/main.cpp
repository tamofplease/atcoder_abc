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
    vector<vector<int>> c(3, vector<int>(3));
    rep(i, 3) rep(j, 3) cin >> c[i][j];
    rep(a_1, 101) rep(a_2, 101) rep(a_3, 101) {
        bool valid = true;
        rep(i, 3) {
            int c_1 = c[i][0]; int c_2 = c[i][1]; int c_3 = c[i][2];
            if(c_1-a_1 != c_2-a_2 || c_2-a_2 != c_3-a_3) {
                valid = false;
            }
        }
        if(valid) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
