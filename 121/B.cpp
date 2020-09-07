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
int main(){
    int N,M;cin >> N >> M;
    int C; cin >> C;
    const int MAXM = 21;
    int B[MAXM];rep(i,M)cin >> B[i];
    int A[MAXM][MAXM];rep(i,N)rep(j,M)cin >> A[i][j];
    int ans = 0;
    rep(i,N){
        int tmp = C;
        rep(j,M){   
            tmp += A[i][j]*B[j];
        }
        if(tmp>0)ans++;
    }

    cout << ans << endl;
    return 0;
}