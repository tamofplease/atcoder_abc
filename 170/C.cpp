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
const int MAXN = 102;
int main(){
    int X,N;cin >> X >> N;
    bool p[MAXN];
    rep(i,MAXN)p[i] = true;
    rep(i,N) {
        int a;cin >> a;
        p[a] = false;
    }
    int i;
    for(i=X;i<=101;i++){
        if(p[i])break;
    }
    int j;
    for(j=X;j>=0;j--) {
        if(p[j])break;
    }
    int tmp;
    if(abs(X-i)>=abs(X-j))tmp = j;
    else tmp = i;
    cout << tmp << endl;
    return 0;
}