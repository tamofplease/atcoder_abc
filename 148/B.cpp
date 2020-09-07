#include <bits/stdc++.h>
#include <numeric>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

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

ll A,B;
ll ans ;
int main(){
    cin >> A >> B;

    cout << lcm(A,B) << endl;
    return 0;
}