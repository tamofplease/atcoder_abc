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
    int q; cin >> q;
    vector<bool> e(500001, true);
    vector<bool> similor(500001, false);
    vector<int> simsum(500001, 0);
    e[0] = false; e[1] = false;
    for(int i=2;i*i<=500000;i++) {
        if(e[i]) {
            int j = i;
            while(j+i <= 500000) {
                j += i; e[j] = false;
            }
        }
    }
    for(int i=1;i<=500000;i+=2) similor[i] = e[i] && e[(i+1)/2];
    rep(i, 500000) simsum[i+1] += simsum[i] + similor[i];
    rep(i, q) {
        int l, r; cin >> l >> r;
        cout << simsum[r] - simsum[l] + similor[r] << endl;
    }
    return 0;
}
