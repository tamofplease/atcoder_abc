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
    int a,b,H,M;
    cin >> a >> b >> H >> M;
    double hd = 0,md = 0;
    bool flag = false;
    for(int i=0;i<12;i++) {
        for(int j=0;j<60;j++) {
            if(i==H && M==j){
                flag = true;
                break;
            }
            hd += 0.5;
            md += 6.0;
        }
        if(flag)break;
        md = 0;
    }
    double under = abs(hd-md);
    double x = under* M_PI / 180; 
    double ans = sqrt(a*a + b*b  - 2*a*b*cos(x));
    printf("%.15f\n",ans);

    return 0;
}