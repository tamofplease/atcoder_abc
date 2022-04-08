#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

void show(vector<int>& v) {
    for(int i: v) cout << i << " ";
    cout << endl;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> f(n, vector<int>(10)), p(n, vector<int>(11));
    rep(i, n) {
        rep(j, 10) cin >> f[i][j];
    }
    rep(i, n) {
        rep(j, 11) cin >> p[i][j];
    }
    int ans = INT32_MIN;
    for(int i=0;i<(1<<10);i++) {
        vector<int> dates;
        for(int date=0;date<10;date++) {
            if(i&(1<<date)) {
                dates.push_back(date);
            }
        }
        if(dates.empty()) continue;
        int tmp = 0;
        rep(i,n) {
            int tm = 0;
            for(int dt: dates) {
                if(f[i][dt]) tm++;
            }
            tmp += p[i][tm];
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
