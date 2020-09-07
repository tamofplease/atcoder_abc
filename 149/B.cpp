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

ll A,B,K;
int main(){
    cin >> A >> B >> K;
    if(A>=K){
        cout << A-K <<" " << B << endl;
    }else if(K>=A && B>=(K-A)){
        cout << 0 << " " << B-(K-A) << endl;
    }else{
        cout << 0 << " " << 0 << endl;
    }

    return 0;
}