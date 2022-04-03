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
    vector<char> t(3);
    rep(i,3) cin >> t[i];
    int possible = 0;
    rep(i,3) {
        char c; cin >> c;
        if(t[i] != c) possible++;
    }
    if(possible == 2) puts("No");
    else puts("Yes");
    return 0;
}