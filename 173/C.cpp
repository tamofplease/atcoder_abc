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

char c[7][7];
char tmp[7][7];
int H,W,K;
void cpy(){
    rep(i,H)rep(j,W)tmp[i][j]= c[i][j];
}

void showtmp() {
    rep(i,H){
        rep(j,W) {
            cout << tmp[i][j];
        }
        cout << endl;
    }
}

int main(){
    cin >> H >> W >>K;

    rep(i,H)rep(j,W){
        cin >> c[i][j];
    }
    
    int ans = 0;

    for(int i=0;i<(1<<H);i++) {
        for(int j=0;j<(1<<W);j++) {
            cpy();
            for(int bit=0;bit<H;bit++) {
                for(int bin=0;bin<W;bin++) {
                    if(i&(1<<bit)) {
                        for(int k=0;k<W;k++) tmp[bit][k] = 'r';
                    }
                    if(j&(1<<bin)) {
                        for(int k=0;k<H;k++) tmp[k][bin] = 'r';
                    }
                }
            }
            int counter = 0;
            rep(r,H)rep(l,W)if(tmp[r][l]=='#')counter++;
            if(counter==K)ans++;
        }
    }

    cout << ans << endl;
    return 0;
}