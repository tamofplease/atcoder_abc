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
    vector<pair<int, int>> a(n), b(n);
    rep(i, n) {
        cin >> a[i].first >> a[i].second;
    }
    rep(i, n) {
        cin >> b[i].first >> b[i].second;
    }
    sort(ALL(a)); sort(ALL(b));
    int ans = 0;
    rep(i, n) {
        int tmp = -1;
        int idx = -1;
        rep(j, n) {
            if(a[j].first < b[i].first && a[j].second < b[i].second ) { // bのxがaのxよりも小さい
                if(tmp < a[j].second) { // かつaのy座標が、最大
                    tmp = a[j].second;
                    idx = j;
                }
            }
        }
        if(idx != -1) {
            ans++;
            a.erase(a.begin() + idx);
        }
    }
    cout << ans << endl;
    return 0;
}
