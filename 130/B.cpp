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
const int maxn = 100;
int main(){
    int n,x;
    cin >> n >> x;
    
    int l[maxn];
    int counter = 0;
    rep(i,n) {
        cin >> l[i];
    }
    int num = 1;
    for(int i=1;i<=n;i++) {
        counter = counter + l[i-1];
        if(counter > x)break;
        num++;
    }
    cout << num << endl;
    return 0;
}