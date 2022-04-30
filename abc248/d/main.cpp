#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)

#define ll long long

int main() {
    int n; cin >> n;
    vector<vector<int>> d(n+1);
    rep(i,n) {
        int a; cin >> a;
        d[a].push_back(i);
    }
    int query; cin >> query;
    rep(i,query) {
        int l,r,x; cin >> l >> r >> x;
        l--;r--;
        if(d[x].size() == 0) {
            cout << 0 << endl;
            continue;
        }
        auto up = upper_bound(d[x].begin(), d[x].end(), r);
        auto lw = lower_bound(d[x].begin(), d[x].end(), l);
        cout <<  up - lw << endl;
    }
    ///  1 2 3 4 4 5
    ///  
    return 0;
}