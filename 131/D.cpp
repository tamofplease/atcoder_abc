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
    int N,L;
    cin >> N >>L ;
    int taste = 0;
    int mi = 1000000;
    for(int i=1;i<=N;i++){
        taste += (i+L-1);
        if(abs(i+L-1)<abs(mi))mi = i+L-1;
    }
    cout << taste-mi << endl;
    return 0;
}