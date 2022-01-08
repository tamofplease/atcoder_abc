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
    int n; cin >> n;
    vector<int> a(n),b(n);
    rep(i, n) cin >> a[i] >> b[i];
    double whole_time = 0;
    rep(i, n) whole_time += (double)a[i] / b[i];
    whole_time /= 2;
    double ans = 0;
    int i = 0;
    while(whole_time > 0) {
        if((double)whole_time * b[i] >= a[i]) {
            whole_time -= (double)a[i] / b[i];
            ans += a[i];
        } else {
            ans += whole_time * b[i];
            break;
        }
        i++;
    }
    printf("%0.15f\n", ans);
    return 0;
}
