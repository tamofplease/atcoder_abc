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
    int n, m, x; cin >> n >> m >> x;
    vector<int> a(m);
    vector<int> table(n+1, 0);
    rep(i, m) {
        int a; cin >> a;
        table[a]++;
    }
    int ans = 0;
    for(int i=1+x;i<n;i++) {
        if(table[i] == 1) ans++;
    }
    int tmp = 0;
    for(int i=1;i<x;i++) {
        if(table[i]) tmp++;
    }
    cout << min(ans, tmp) << endl;

    return 0;
}
