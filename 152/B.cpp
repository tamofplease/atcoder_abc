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
    int a,b;
    cin >> a >> b;
    int A = 0,B = 0;
    rep(i,a){
        A += b;
        A*= 10;
    }
    rep(i,b){
        B += a;
        B *= 10;
    }
    A /= 10;
    B /=  10;
    if(A>B)cout << A << endl;
    else cout << B << endl;
    return 0;
}