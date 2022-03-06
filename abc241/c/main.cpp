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
    int n; cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    bool ans = false;
    auto check = [&](int col, int row) {
        /// row-dir
        if(row+5<n) {
            int cnt = 0;
            rep(i,6) if(s[col][row+i] == '#') cnt++;
            if(cnt >= 4) ans = true;
        }
        /// col-dir
        if(col+5<n) {
            int cnt = 0;
            rep(i,6) if(s[col+i][row] == '#') cnt++;
            if(cnt >= 4) ans = true;
        }

        /// diagonal
        if(row+5<n && col+5<n) {
            int cnt = 0;
            rep(i,6) if(s[col+i][row+i] == '#') cnt++;
            if(cnt >= 4) ans = true;
        }
        if(row-5>=0 && col+5<n) {
            int cnt = 0;
            rep(i,6) if(s[col+i][row-i] == '#') cnt++;
            if(cnt >= 4) ans = true;
        }
    };
    rep(c,n) rep(r,n) {
        check(c, r);
        if(ans) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
