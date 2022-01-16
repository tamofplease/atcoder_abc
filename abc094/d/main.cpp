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
    int n; cin >> n;
    vector<int> a(n);
    int N=0, R=0;
    rep(i, n) {
        cin >> a[i];
        N = max(N, a[i]);
    }
    sort(ALL(a));
    if(N%2==0) {
        int target = N/2;
        int diff = INT32_MAX;
        rep(i, n) {
            int df = abs(target - a[i]);
            if(diff > df) {
                diff = df;
                R = a[i];
            }   
        }
        cout << N  << " " << R << endl;
        return 0;
    }
    int first_target = (N+1) / 2;
    int second_target = (N-1) / 2;
    int diff =  INT32_MAX;
    rep(i, n) {
        int df = abs(first_target-a[i]);
        int df2 = abs(second_target-a[i]);
        if(diff > df) {
            diff = df;
            R = a[i];
        }
        if(diff > df2) {
            diff = df2;
            R = a[i];
        }
    }
    cout << N << " " << R << endl;


    return 0;
}
