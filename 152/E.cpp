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

ll gcd(ll a,ll b)
{
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int N;
#define MAXN 40000



ll A[MAXN];

int main(){
    cin >> N;
    ll ma = 1;
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        ma = lcm(ma,A[i]);
        //ma %= MOD;
    }
    ll ans = 0;
    
    rep(i,N){
        ans += (ma/A[i]) %MOD;
    }
    cout << ans%MOD << endl;
    return 0;
}