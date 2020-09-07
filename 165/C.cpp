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

string s;
int N,M,Q;

string retnum(int p){
    s = "00000000000";
    int i = 0;
    while(1){
        int tmp = p%M;
        s[i] = tmp;
        i++;p/=M;
        if(p<=0)break;
    }
    if()
    return s;
}

int dp[11][11][11] = {0}; //iとjの間をkにした時に得られるポイント

const int MAXQ = 51;
int a[MAXQ],b[MAXQ],c[MAXQ],d[MAXQ];
int main(){
    cin >> N >> M >> Q;
    rep(i,Q)cin >> a[i]>> b[i] >> c[i] >> d[i];

    rep(i,N)for(int j=i;j<N;j++)rep(k,M){
        dp[a[i]][b[j]][c[k]] += d[]
    }

    return 0;
}