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

const int MAXN=200000;
int A[MAXN];

int main(){
    int k,n;
    cin >> k >> n;
    rep(i,n){
        cin >> A[i];
    }

    sort(A, A+n);
    int maxi = min(k-(A[n-1] - A[0]),A[n-1] - A[0]);
    rep(i,n-1){
        maxi = max((A[i+1]-A[i]),maxi);
    }
    cout << k - maxi << endl;

    return 0;
}