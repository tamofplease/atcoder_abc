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
    int n, a, b; cin >> n >> a >> b;
    int ans = 0;
    Rep(i, n) {
        string s = to_string(i);
        int tmp = 0;
        for(char c: s) {
            tmp += c - '0';
        }
        if(a <= tmp && tmp <= b) ans+=i;
    }
    cout << ans << endl;
    return 0;
}
