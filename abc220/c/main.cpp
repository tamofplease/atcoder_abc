#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int N;
int main(){
    cin >> N;
    ll sum = 0;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    ll X;cin >> X;
    ll r = X / sum;
    ll ans = r * N;
    ll now = r * sum;
    rep(i, N) {
        now += A[i];
        ans++;
        if(now > X) {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
