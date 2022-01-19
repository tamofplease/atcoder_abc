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
    vector<pair<int, pair<int, int>>> v(n+1);
    v[0] = make_pair(0, make_pair(0, 0));
    Rep(i, n) {
        pair<int, int> dim;
        int t;
        cin >> t >> dim.first >> dim.second;
        v[i] = make_pair(t, dim);
    }
    sort(ALL(v));
    rep(i, n) {
        int time_diff = v[i+1].first - v[i].first;
        pair<int, int> cur_dim = v[i].second; 
        pair<int, int> next_dim = v[i+1].second;
        int df = abs(cur_dim.first - next_dim.first) + abs(cur_dim.second - next_dim.second);
        if(time_diff == df) continue;
        if(time_diff > df && (time_diff - df) % 2 == 0) continue;
        puts("No");
        return 0;
    }
    puts("Yes");
    return 0;
}
