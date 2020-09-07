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
    int N,K;
    int MAXN=101;
    bool OK[101];
    rep(i,101)OK[i] = false;
    cin >> N  >> K;    
    rep(i,K) {
        int d;
        cin >> d;
        rep(j,d) {
            int a;
            cin >> a;
            OK[a] = true;
        }
    }
    int count = 0;
    for(int i=1;i<=N;i++) {
        if(!OK[i])count++;
    }
    cout << count << endl;
    return 0;
}