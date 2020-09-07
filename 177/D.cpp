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
using GraphEdge = vector<vector<edge>> ;

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
const int MAXM = 200000;
bool has_been[MAXM];

int ans = 0;
int counter = 0;
void sear(const Graph &G, int first_node){
    counter++;
    has_been[first_node] = true;
    ans = max(counter, ans);
    for(int j : G[first_node]){
        if(!has_been[j]){
            sear(G,j);
        }
    }
}

int main(){
    int N,M;cin >> N >> M;
    memset(has_been, false, sizeof(has_been));
    Graph G(MAXM);
    rep(i,M){
        int a,b;cin >>a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    Rep(i,N){
        counter = 0;
        if(!has_been[i])sear(G,i);
    }

    cout << ans << endl;

    return 0;
}