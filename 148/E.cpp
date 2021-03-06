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
    int N;
    string S,T;
    cin >> N >> S >> T;
    string ST;
    int count = 0;
    for(int i=0;i<N*2;i++){
        ST[i] = S[count];
        i++;
        ST[i] = T[count];
        count++;
    }
    rep(i,2*N){
        cout << ST[i];
    }
    cout <<  endl;
    return 0;
}