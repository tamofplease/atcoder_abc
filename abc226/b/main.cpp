#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int main() {
    int n; cin >> n;
    set<vector<int>> se;
    rep(i, n) {
        int l; cin >> l;
        vector<int> a(l);
        rep(i, l) {
            cin >> a[i];
        }
        se.insert(a);
    }
    cout << se.size() << endl;
    return 0;
}
