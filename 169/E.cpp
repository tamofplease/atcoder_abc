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

#define MAXN 200000
#define MAXAB 1000000001

int N;

int A[MAXN],B[MAXN];

int solve_even() {
    sort(A,A+N);
    sort(B,B+N);

    return (B[N/2] + B[(N/2)-1])  - (A[N/2] + A[(N/2)-1]) + 1;

}

int solve_odd() {
    sort(A,A+N);
    sort(B,B+N);
    return B[N/2] - A[N/2] +1;
}

int main(){
    cin >> N;
    rep(i,N) cin >> A[i] >> B[i];
    int ans = N%2==1 ? solve_odd() : solve_even();
    cout << ans << endl;
    
    return 0;
}