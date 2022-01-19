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
    int n, h; cin >> n >> h;
    vector<int> throw_attacks(n); // 投げる攻撃
    int  normal_max = 0; // 通常攻撃の最大
    rep(i, n) {
        int na; cin >> na >> throw_attacks[i];
        normal_max = max(na, normal_max);
    }

    sort(ALL(throw_attacks), greater<int>());
    
    int ans = 0;

    rep(i, n) {
        if(throw_attacks[i] < normal_max || h <= 0) break;
        ans++;
        h -= throw_attacks[i];
    }

    // cout << ans << " " << h << endl;

    if(h>0) {
        ans += (h / normal_max);
        if(h%normal_max != 0) ans++;
    }
    cout << ans << endl;
    return 0;
}
