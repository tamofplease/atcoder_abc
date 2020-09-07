#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

struct edge{
    int to,weight;
    edge(int to,int weight):to(to),weight(weight){}
};
using Graph = vector<vector<int>> ;
using GraphEdge = vector<vector<int>> ;

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

const int MAXH=300001;
const int MAXW=300001;
int main(){
    int H,W,M;cin >> H >> W >> M;
    int tate[MAXW];
    int yoko[MAXH];
    bool onw[MAXW];
    bool onh[MAXW];

    memset(onw, false, sizeof(onw));  
    memset(onh, false, sizeof(onh));  
    memset(tate, 0, sizeof(tate));
    memset(yoko, 0, sizeof(yoko));
    int h[MAXH];
    int w[MAXW];
    rep(i,M){
        cin >> h[i] >> w[i];
        tate[w[i]]++;
        yoko[h[i]]++;
    }
    ll ans = 0;
    int maxw=0,maxh=0;
    ll x=0,y=0;
    Rep(i,W){
        maxw = max(tate[i],maxw);
    }
    Rep(i,W){
        if(maxw==tate[i]){
            onw[i] = true;
            x++;
        }
    }

    Rep(i,H){
        maxh = max(maxh,yoko[i]);
    }

    Rep(i,H){
        if(maxh==yoko[i]){
            onh[i] = true;
            y++;
        }
    }

    ans = x*y;
    rep(i,M){
        if(onw[w[i]] && onh[h[i]]){
            ans--;
        }
    }

    if(ans>0)cout << maxh+maxw << endl;
    else cout << maxh+maxw-1 << endl;

    return 0;
}