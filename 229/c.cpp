#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
const int MAXN = 3300000;
int N, W;
vector<pair<ll, ll>> C;
void input() {
    cin >>  N >> W;
    rep(i, N) {
        int a,b; cin >> a >> b;
        C.push_back(make_pair(-1 * a, b));
    }
}
void solve() {
    sort(C.begin(), C.end());
    ll ans = 0;
    rep(i, N) {
        if(W >= C[i].second) {
            ans -=  C[i].first * C[i].second;
            W -= C[i].second;
            continue;
        }
        if (W == 0) {
            break;
        }
        ans -= W * C[i].first;
        break;
    }
    cout << ans << endl;
}

int main(){
    input();
    solve();
    return 0;
}
