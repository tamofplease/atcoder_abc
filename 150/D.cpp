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

ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}

#define MAXN 100001

int main(){
    ll N,M;
    ll a[MAXN];
    cin >> N >> M;
    rep(i,N){
        cin >> a[i];
        a[i]/=2;
    }
    ll num = 1;
    for(ll i=0;i<N;i++){
        num = lcm(num,a[i]);
    }
    ll cou = 0;
    if(num==1)cout << ((M/num)-1)/2 << endl;
    else cout << ((M/num)+1)/2 << endl;

    return 0;
}