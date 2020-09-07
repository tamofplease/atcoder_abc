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
int N,K;
int R,S,P;
string T;

#define MAXN 100000
ll score[MAXN];
int main(){
    char data[MAXN*2+1];
    cin >> N >> K >> R >> S >> P >> T;
    rep(i,N)score[i] = 0;
    rep(i,2*N){
        data[i] = 0;
    }
    rep(i,N){
        if(T[i]=='s'){
            T[i] = 'r';
            
        }else if(T[i]=='r'){
            T[i]='p';
        }else T[i]='s';
    }
    for(int i=0;i<N;i++){
        if(T[i]=='s')score[i] = S;
        if(T[i]=='r')score[i] = R;
        if(T[i]=='p')score[i] = P;
    }

    ll ans = 0;
    for(int i=0;i<N;i++){
        if(T[i]=='s' && data[i]!='s'){
            ans += S;
            data[i+K]='s';
        }else if(T[i]=='r' && data[i]!= 'r'){
            ans += R;
            data[i+K]='r';
        }else if(T[i]=='p' && data[i]!= 'p'){
            ans += P;
            data[i+K]='p';
        }
    }
    cout << ans << endl;
    return 0;
}