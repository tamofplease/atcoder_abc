#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int N;
int main(){
    cin >> N;
    vector<pair<int, int>> co(N);
    rep(i, N) {
        cin >> co[i].first >> co[i].second;
    }
    sort(co.begin(), co.end());

    rep(i, N) {
        rep(j, i) {
            int dx1 = co[j].first - co[i].first;
            int dy1 = co[j].second - co[i].second;
            rep(k, j) {
                int dx2 = co[k].first - co[j].first;
                int dy2 = co[k].second - co[j].second;
                if(dy2 == 0 && dy1 == 0) {
                    puts("Yes"); return 0;
                }
                if(dy2 == 0 || dy1 == 0) {
                    continue;
                }
                ll a = (ll)dx1 * dy2;
                ll b = (ll)dy1 * dx2;
                if(a == b) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    puts("No");
    return 0;
    
    return 0;
}
