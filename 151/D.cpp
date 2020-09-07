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

int H,W;
#define MAXN 21
int S[MAXN][MAXN];
int x[4] = {1,0,-1,0};
int y[4] = {0,1,0,-1};

int checker[MAXN][MAXN];

int set(int x_s,int y_s,int x_g,int y_g){
    rep(i,4){
        int x_next = x_s+x[i];
        int y_next = y_s+y[i];
        if(s[x_next][y_next]!='#' && x_next<W && 0<=x_next && y_next<H && y_next>=0){

        }
    }
}

int main(){
    cin >> H >> W;
    rep(i,H)rep(j,W){
        cin >> S[i][j];
    }
    int ma = 0;
    rep(i,H)rep(j,W)rep(k,H)rep(l,W){
        
        if(S[i][j]!='#'&&S[k][l]!='#')ma = max(ma,set(i,j,k,l));
    }
    return 0;
}