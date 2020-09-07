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

int H,W,K;

const int MAXH = 10,MAXW=1000;
bool S[MAXH][MAXW];

int main(){
    cin >> H >> W >> K;
    int count[MAXW];
    rep(i,H)rep(j,W){
        char c; cin >> c;
        if(c){
            count[i]++;
            S[i][j] = true;
        }else{
            S[i][j] = false;
        }
    }

    for(int i=0;i<(1<<H);i++){
        for(int bit=0;bit<=H;bit++) {
            if(i&bit) {
                cout << bit  <<" ";
            }
        }
        cout << endl;
    }
    

    return 0;
}