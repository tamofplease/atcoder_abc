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
    int N;cin >> N;
    const int MAXN = 100000;
    ll A[MAXN];
    ll mi = LLONG_MAX;
    bool neg=false;
    ll ans = 0;
    rep(i,N)cin >> A[i];
    rep(i,N-1){
        ll a=A[i];
        if(a<0){
            A[i+1] = -A[i+1];
            mi = min(-a, mi);
            ans += -a;
        }else {
            ans += a; 
            mi = min(a,mi);
        }
    }
    if(A[N-1]<=0){
        if(mi>abs(A[N-1])){
            ans += A[N-1];
        }else {
            ans -= A[N-1];
            ans -= mi*2;
        }
        cout << ans << endl;

    }else if(A[N-1]>=0){
        ans += A[N-1];
        cout << ans << endl;
    }
    

    return 0;
}