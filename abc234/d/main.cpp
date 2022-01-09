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
    int n, k; cin >> n >> k;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    int ans = 550000;
    rep(i, k) {
        ans = min(p[i], ans);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    rep(i, k) {
        if(p[i] > ans) {
            pq.push(p[i]);
        }
    }
    cout << ans << endl;
    for(int i=k;i<n;i++) {
        if(p[i] > ans) {
            pq.push(p[i]);
            ans = pq.top(); pq.pop();
        }
        cout << ans << endl;
    }
    return 0;
}
