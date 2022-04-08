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
    int n; cin >> n;
    vector<pair<ll, int>> v;
    rep(i, n) {
        ll a, b; cin >> a >> b;
        v.push_back(make_pair(a, 1));
        v.push_back(make_pair(a+b, -1));
    }
    sort(ALL(v));
    ll userNums = 0;
    ll beforeDays = 0;
    vector<ll> ans(n+1);
    ll vSize = v.size();

    rep(i, vSize) {
        ans[userNums] += v[i].first - beforeDays;
        beforeDays = v[i].first;
        userNums += v[i].second;
        while(i + 1 < vSize && v[i].first == v[i+1].first) {
            userNums += v[++i].second;
        }
    }
    cout << ans[1];
    for(int i = 2; i <= n ; i++) {
        cout << " " << ans[i];
    }
    cout << endl;
    

    return 0;
}
