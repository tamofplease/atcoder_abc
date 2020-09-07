#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

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
    int A,B,C,K;
    cin >> A >> B >> C >> K;
    int ans = 0;
    ans += min(A,K);
    if(K>(A+B)) {
        cout << ans - min(K-A-B,C) << endl;
    }else {
        cout << ans << endl;
    }

    
    return 0;
}