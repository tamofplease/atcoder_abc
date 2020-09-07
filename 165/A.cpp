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
    int K;cin >> K;
    int A,B;cin >> A >> B;
    int tmp = 1;
    bool ok = false;
    int tmo = K;
    while(1){
        tmo = K*tmp;
        tmp++;
        if(tmo>=A && tmo<=B){
            ok = true;
            break;
        }else if(tmo>B)break;
    }
    if(ok)cout << "OK" << endl;
    else cout << "NG" << endl;
    return 0;
}