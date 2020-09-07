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
ll A,C,B,D;
ll gcd(ll a, ll b)
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
void solve(){
    ll x = (A-1)/C;
    ll y = (A-1)/D;
    ll z = (A-1)/(lcm(C,D));
    ll ans1 = (A-1)-(x+y-z);
    ll X = B/C;
    ll Y = B/D;
    ll Z = B/(lcm(C,D));
    ll ans2 = B-(X+Y-Z);
    cout << ans2 - ans1 << endl;
}

int main(){
    cin >> A >> B >> C >> D;
    solve();
    return 0;
}
