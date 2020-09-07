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


int main(){
    ll X ;
    ll A,B;
    cin >> X;
    for(int i=-200;i<=200;i++) {
        ll s = pow(i,5);
        for(int j=-200;j<=200;j++)  {
            ll k = pow(j,5);
            if(s-k==X){
                A = i;
                B = j;
            }
        }
    }

    cout << A << " " << B << endl;
    
    return 0;
}