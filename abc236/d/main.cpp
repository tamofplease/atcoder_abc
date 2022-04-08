#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

vector<vector<pair<int, int>>> ans;

void recursion_comb(vector<pair<int, int>> p, set<int> remain) {
    if(remain.empty()) {
        ans.push_back(p);
        return;
    }
    auto it = remain.begin();
    int mi = *it;
    remain.erase(it);
    for(int nxt: remain) {
        set<int> nr = remain;
        vector<pair<int, int>> np = p;
        np.push_back(make_pair(mi, nxt));
        nr.erase(nxt);
        recursion_comb(np, nr);
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    set<int> rem;
    map<pair<ll,ll>, ll> a;
    rep(i, n*2) rem.insert(i);
    for(ll i=0;i<2*n-1;i++) {
        for(ll j=i+1;j<2*n;j++) {
            cin >> a[make_pair(i, j)];
        }
    }
    vector<pair<int, int>> vp;
    recursion_comb(vp, rem);
    ll result = 0;
    rep(i, ans.size()) {
        ll tmp = 0;
        rep(j, ans[i].size()) {
            if(tmp == 0) {
                tmp = a[make_pair(ans[i][j].first, ans[i][j].second)];
            } else {
                tmp ^= a[make_pair(ans[i][j].first, ans[i][j].second)];
            }
        }
        result = max(result, tmp);
    }
    cout << result << endl;
    return 0;
}
