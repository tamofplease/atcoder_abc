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

ll gcd(ll a,ll b) {
    if(b==0)return a;
    return gcd(b, a%b);
}

ll three_gcd(ll a,ll b,ll c){
    return gcd(gcd(a,b),c);
}

int main(){
    int K;cin >> K;
    ll ans = 0;
    Rep(i,K)Rep(j,K)Rep(k,K){
        ans += three_gcd(i,j,k);
    }
    cout << ans << endl;
    return 0;
}