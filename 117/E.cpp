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
    const int MAXM = 100000;
    ll X[MAXM];
    priority_queue<int> PQ;
    int sum = 0;
    ll mi = INT32_MAX;
    ll ma = INT32_MIN;
    rep(i,M){
        cin >> X[i];
        mi = min(mi,X[i]);
        ma = max(ma,X[i]);

    }
    if(N>=M){
        cout << 0 << endl;
        return 0;
    }
    // cout << mi << " " << ma << endl;
    sort(X,X+M);
    
    rep(i,M){
        if(i>0)PQ.push(X[i]-X[i-1]);
    }

    int ans = ma-mi;

    for(int i=0;i<N-1;i++){
        if(!PQ.empty()){
            ans -= PQ.top();
            PQ.pop();
        }
    }

    cout << ans << endl;
    



    return 0;
}