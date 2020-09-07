#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)


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
    int A,B;
    cin >> A >> B;
    int i=0;
    
    while(1){
        if( int(i*0.08) > A && int(i * 0.1) > B){
            cout << -1 << endl;
            return 0;
        }
        if(int(i * 0.08) == A && int(i * 0.1) == B){
            break;
        }
        i++;
    }
    
    
    cout << i << endl;
    
    return 0;
}