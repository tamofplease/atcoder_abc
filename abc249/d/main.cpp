#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define all(a) a.begin(), a.end()
#define ll long long

vector<pair<int,int>> div(int a) {
    vector<pair<int,int>> v;
    for(int i=1;i*i<=a;i++) {
        if(a%i == 0) {
            v.push_back({i, a/i});
        } 
    }
    return v;
}

int main() {

    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int k : a) {
        /// 2 3 6
        vector<pair<int,int>> ns = div(k);
        for(pair<int,int> p : ns) {
            if(p.first == p.second) {
                auto itl = lower_bound(all(a), p.first);
                auto itr = upper_bound(all(a), p.first);
                // 1 2 3 4 4 5
                ans += (itr - itl) * (itr - itl);
                continue;
            } 
            auto sl = lower_bound(all(a), p.first);
            auto sr = upper_bound(all(a), p.first);
            auto lel = lower_bound(all(a), p.second);
            auto lr = upper_bound(all(a), p.second);
            ans += 2 * (sr - sl) * (lr - lel);
        }
    }
    cout << ans << endl;
    return 0;
}