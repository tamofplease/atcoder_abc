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
    int N,K;cin >> N >> K;
    double ans = 0;
    Rep(i,N){
        double tmp = (double)i;
        int count = 0;
        while(tmp<K){
            tmp *= 2;
            count++;
        }
        // cout << count << " " << pow(0.5, count) << endl;
        if(count>0)ans += (double)((double)(1.0/(double)N) * pow(0.5, count));
        else ans += (double)(1.0/(double)N);
    }
    printf("%0.12f\n", ans);
    return 0;
}