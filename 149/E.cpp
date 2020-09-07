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
int N,M;
#define MAXN 100000
int A[MAXN];
int B[MAXN];

bool sor(int a,int b){
    if(a>b)return true;
    return false;
}

int main(){
    cin >> N >> M ;
    rep(i,N){
        cin >> A[i];
    }
    sort(A,A+N,sor);
    rep(i,N)B[i] = A[i];
    ll ans = 0;
    int a=0;
    int b = 0;

    for(int j=0;j<M;j++){
        ans += A[a]+B[b];
        int nextA = A[a+1];
        int nextB = B[a+1];

        if(A[a]+nextB>B[b]+nextA){
            b++;
        }else{
            a++;
        }
    }
    cout << ans << endl;
    return 0;
}