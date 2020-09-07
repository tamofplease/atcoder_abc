#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
 
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
 
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
 
#define MAXN 300001
ll N;
ll A[MAXN];
void set_data(){    
    cin >> N ;
    rep(i,MAXN)A[i] = 0;
    rep(i,N)cin >> A[i];
    return;
}
 
 
int main(){
    set_data();
    
    ll ans = 0;
    ll tmp = 1ll;
    for(ll j=0;j<60;j++){
        ll tmp = (1ll<<j);
        ll One = 0,Zero  = 0;
        for(ll i=0;i<N;i++){
            if(tmp&A[i]){
                One++;
            }
            else Zero++;
        }
        tmp %= MOD;
        ll k = (tmp*One*Zero)%MOD;
        ans %= MOD;
        ans += k%MOD;
        ans %= MOD;
    }
    cout << ans%MOD << endl;
    return 0;
}