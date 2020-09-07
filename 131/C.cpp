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
int N;


int A[MAXN],B[MAXN];


void solve(){
    pair<int,int> C[MAXN];
    rep(i,N)C[i] = make_pair(B[i],A[i]);
    sort(C,C+N);
    int time =0;
    rep(i,N){
        time += C[i].second;
        if(time>C[i].first){
            puts("No");
            return;
        }
    }
    puts("Yes");
}
int main(){
    cin >> N ;
    rep(i,N) cin >> A[i] >> B[i];
    solve();
    return 0;
}
