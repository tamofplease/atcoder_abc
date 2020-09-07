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



int H,W;
const int MAXW = 2001;
const int MAXH = 2001;
string S[MAXH];
int tate[MAXH][MAXW];
int yoko[MAXH][MAXW];

void showtate(){
    rep(i,H){
        rep(j,W)cout << tate[i][j];
        cout << endl;
    }
    cout << endl;
}
void showyoko(){
    rep(i,H){
        rep(j,W)cout << yoko[i][j];
        cout << endl;
    }
    cout << endl;
}

int main(){

    cin >> H >> W;
    rep(i,H){
        rep(j,W){
            tate[i][j] = 0;
            yoko[i][j] = 0;
        }
        cin >> S[i];
    }

    rep(i,H){
        int counter = 0;
        rep(j,W){
            if(S[i][j]=='.'){
                counter++;
                yoko[i][j]=counter;
            }else {
                counter = 0;
            }
        }
    }
    for(int i=H-1;i>=0;i--){
        for(int j=W-1;j>=1;j--){
            if(yoko[i][j]>=yoko[i][j-1] && S[i][j-1]!='#'){
                yoko[i][j-1] = yoko[i][j];
            }
        }
    }
    // showyoko();
    rep(j,W){
        int counter = 0;
        rep(i,H){
           if(S[i][j]=='.') {
               counter++;
               tate[i][j] = counter;
           }else{
               counter = 0;
           }
        }
    }
    for(int i=W-1;i>=0;i--){
        for(int j=H-1;j>0;j--){
            if(tate[j][i]>=tate[j-1][i] && S[j-1][i] != '#'){
                tate[j-1][i] = tate[j][i];
            }
        }
    }

    int ans = 0;
    

    rep(i,H)rep(j,W){
        int tmp = tate[i][j] + yoko[i][j];
        ans = max(ans, tmp);
    }
    cout << ans-1 << endl;
    

    return 0;
}