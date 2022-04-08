#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    set<int> s;
    Rep(i, 2*n+1) {
        s.insert(i);
    }

    while(true) {
        auto it = s.begin();
        cout << *it << endl;
        s.erase(it);
        int q; cin >> q;
        if(q == 0) break;
        s.erase(q);
    }
    return 0;
}