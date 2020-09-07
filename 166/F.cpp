#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)

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
    int a;

    double mot = 0;
    double chi = 0;
    double chi2 = 0;
    Rep(i,10000)mot += double((double)1/(double)i); 
    Rep(i,1000)chi += double((double)1/(double)i);
    double s= double(chi / mot);
    for(int i=1001;i<=10000;i++)chi2 += double((double)1/(double)i);
    double s2= double(chi2 / mot);
    printf("%.9f\n", s);
    printf("%.9f\n", s2);

    
    
    return 0;
}