#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int main(){
    int N, Q;cin >> N >> Q;
    vector<int> A(N), X(Q);
    rep(i, N) cin >> A[i];
    rep(i, Q) cin >> X[i];
    sort(A.begin(), A.end());
    rep(i, Q) {
        auto itr = lower_bound(A.begin(), A.end(), X[i]);
        auto pos = distance(A.begin(), itr);
        if (itr == A.begin()) {
            cout << N << endl;
        } else if (itr == A.end()) {
            cout << 0 << endl;
        } else if(itr != A.begin()) {
            cout << N - pos << endl;
        }
    }

    return 0;
}
