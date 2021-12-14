#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
ll N, D;
vector<pair<int, int>> V;
void input() {
   cin >> N >> D;
   rep(i, N)  {
       ll l, r;cin >> l >> r;
       V.push_back(make_pair(r, l));
   }
}

void solve() {
    sort(V.begin(), V.end());
    ll cur_end = -1;
    ll ans = 0;
    rep(i, N) {
        if(cur_end != -1 && V[i].second <= cur_end) {
            continue;
        }
        ans++;
        cur_end = V[i].first + D - 1;
    }
    cout << ans << endl;
}

int main(){
    input();
    solve();
    return 0;
}
