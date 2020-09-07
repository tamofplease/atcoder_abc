#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
long long modinv(long long a, long long m=MOD) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
    /*MODの割り算の際に
    a/＝b;
    を
    a *= modinv(b,MOD);
    とする。
        */
}
const int MAXN = 200000;
ll A[MAXN];
int main(){
    map<ll,ll> Ma;
    int N;cin >> N;
    rep(i,N) {
        cin >> A[i];
        Ma[A[i]]++;
    }

    ll sum = 0;
    bool che[MAXN+1] = {false};
    rep(i,N) {
        if(!che[A[i]]) {
            sum += (Ma[A[i]] * (Ma[A[i]]-1))/2;
            che[A[i]] = true;
        }
    }

    // cout << sum << endl;
    rep(i,N) {
        cout << sum - ((Ma[A[i]] * (Ma[A[i]]-1))/2) + ((Ma[A[i]]-1) * (Ma[A[i]]-2))/2 << endl;
    }

    return 0;

}