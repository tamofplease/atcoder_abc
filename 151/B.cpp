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

int N,K,M;
#define MAXN 101
int A[MAXN];

int main(){
    cin >> N >> K >> M;
    rep(i,N-1)cin >> A[i];
    int ave = 0;
    rep(i,N-1)ave += A[i];
    int score = M*N;
    int che = score-ave;
    if(che>K)cout << -1 << endl;
    else cout << max(0,che) << endl;


    return 0;
}