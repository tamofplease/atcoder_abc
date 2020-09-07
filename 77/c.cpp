#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
int N;
int main(){
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);
    rep(i,N)cin >> A[i];
    rep(i,N)cin >> B[i];
    rep(i,N)cin >> C[i];
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    long long ans = 0;
    for(ll i=0;i<N;++i){
        ll k = upper_bound(C.begin(),C.end(),B[i])-C.begin();
        k = N-k;
        ll l = lower_bound(A.begin(),A.end(),B[i])-A.begin();
        ans += k*l;
    }
    cout << ans << endl;
    return 0;
}
