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
    a *= modinv(b,MOD);とする。
*/
}
#define MAXN 100000
int main(){
    int N;
    ll H[MAXN];
    cin >> N;
    rep(i,N)cin >> H[i];
    for(int i=N-1;i>0;i--){
        if(H[i]<H[i-1]){
            H[i-1]--;
        }
    }
    bool ok = true;
    for(int i=0;i<N-1;i++){
        if(H[i]>H[i+1]){
            ok = false;
            break;
        }
    }

    if(ok){
        puts("Yes");
    }else{
        puts("No");
    }

    return 0;
}