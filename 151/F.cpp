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

#define MAXN 50
int x[MAXN],y[MAXN];
int main(){
    int N;
    cin >> N;
    int mx,my,mix,miy;
    int maxx=0,minx=1001,maxy=0,miny=0;
    rep(i,N){
        cin >> x[i] >> y[i];
        maxx = max(maxx,x[i]);
        if(maxx==x[i])my = y[i];
        minx = min(minx,x[i]);
        if(minx==x[i])miy = y[i];
        maxy = max(maxy,y[i]);
        if(maxy==y[i])mx = x[i];
        miny = min(miny,y[i]);
        if(miny==y[i])mix = x[i];
    }
    
    double a = sqrt((maxx-minx)*(maxx-minx)+(my-miy)+(my-miy));
    double b = sqrt((maxy-miny)*(maxy-miny)+(mx-mix)+(mx-mix));
    if(a>b)printf("%.7f\n",a/2);
    else printf("%.7f\n",b/2);
    


    return 0;
}