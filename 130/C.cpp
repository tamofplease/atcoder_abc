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
int main(){
    int w,h,x,y;
    cin >> w >> h >> x >> y;
    if(x*2==w && y*2== h){
        printf("%0.9f",(double)w*h/2 );
        cout <<" 1" << endl;
    }else {
        printf("%0.9f",(double)w*h/2 );
        cout << " 0" << endl;
    }
    return 0;
}