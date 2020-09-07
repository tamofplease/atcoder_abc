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

#define MAXN 200001

ll C[MAXN+1];
ll a,b,n;
void calc2(){
    C[0] = 1;
    C[1] = n;
    int k = n/2;
    for(ll i=2;i<=200001;i++){
        C[i] = ((C[i-1]*(n-i+1)%MOD)*modinv(i,MOD));
        C[i] %= MOD;
    }
}

ll mypow(ll x,ll n,ll m){
    ll res = 0;
    if(n == 0) return 1;
    if(n %2 == 0)return mypow(x*x%m,n/2,m);
    else return x*mypow(x,n-1,m)%m;
}


int main(){
    cin >> n >> a >> b;
    calc2();
    ll ans = mypow(2,n,MOD);
    ans = ans - C[a]-C[b];
    while(ans < 0){
        ans += MOD;
    }
    cout << ans-1 << endl;
    return 0;
}