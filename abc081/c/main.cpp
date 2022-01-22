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
    int n, k; cin >> n >> k;
    map<int, int> ma;
    rep(i, n) {
        int a; cin >> a;
        ma[a] += 1;
    }
    vector<pair<int, int>> v;
    for(auto it : ma) {
        v.push_back(make_pair(it.second, it.first));
    }
    sort(ALL(v));
    int ans = 0;
    rep(i, (int)v.size()-k) {
        ans+=v[i].first;
    }
    cout << ans << endl;


    return 0;
}
