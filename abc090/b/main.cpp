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
    int ans = 0;
    for(int i=a;i<=b;i++) {
        string t = to_string(i);
        reverse(t.begin(), t.end());
        if(t == to_string(i)){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
