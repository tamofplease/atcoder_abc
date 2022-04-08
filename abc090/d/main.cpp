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
    int n, k; cin >> n >> k;
    // a % b >= k;
    // <=> a / b = c ...k;
    // a => b * c + k;
    // a - b * c >= k
    // a <= N
    // k <= a <= N
    
    int ans = 0;
    Rep(b, n) {
        int tmp = 0; 
        while(tmp <= n-k) {
            tmp += b;
            ans++;
        }
    }
    return 0;
}
