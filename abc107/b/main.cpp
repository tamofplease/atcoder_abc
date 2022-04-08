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
    int h, w; cin >> h >> w;
    set<int> rh, rw;
    vector<string> a(h);
    rep(i, h) {
        cin >> a[i];
    }
    bool removal = true;
    rep(i, h) {
        removal = true;
        rep(j, w) {
            if(a[i][j] == '#') {
                removal = false;
                break;
            }
        }
        if(removal) rh.insert(i);
    }
    rep(i, w) {
        removal = true;
        rep(j, h) {
            if(a[j][i] == '#') {
                removal = false;
                break;
            }
        }
        if(removal) rw.insert(i);
    }
    rep(i, h) {
        if(rh.find(i) != rh.end()) continue;
        rep(j, w) {
            if(rw.find(j) == rw.end()) {
                cout << a[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
