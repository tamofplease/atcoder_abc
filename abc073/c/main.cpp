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
    map<int, bool> ma;
    int n; cin >> n;
    rep(i, n) {
        int a; cin >> a;
        if(ma.find(a) == ma.end()) {
            ma[a] = true; 
        } else {
            ma.erase(a);
        }
    }
    cout << ma.size() << endl;
    return 0;
}
