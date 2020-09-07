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

int N;
const int MAXN=200000;

int A[MAXN];

bool rev(const int &a, const int &b) {
    return (a>b);
}

int main(){
    cin >> N;
    rep(i,N)cin >> A[i];

    sort(A,A+N,rev);
    
    if(N==2){
        cout << A[0] << endl;
        return 0;
    }

    ll ans  = A[0];
    int counter = 1;
    bool nxt = false;
    for(int i=1;i<=N-2;i++) {
        ans += A[counter];
        if(nxt)counter++;
        nxt = !nxt;
    }   

    cout << ans << endl;

    
    
    return 0;
}