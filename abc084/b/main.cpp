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
    int a, b; cin >> a >> b;
    string s; cin >> s;
    bool first = true;
    rep(i, (int)s.length()) {
        if(s[i] == '-') first = false;
        else if(first) a--;
        else b--;
    }
    if(a == 0 && b == 0 && !first) puts("Yes");
    else puts("No");
    return 0;
}
