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

int N;
const int MAXN = 100001;
typedef vector<vector<int> > Graph;
int color[MAXN] = {0};
int a[MAXN],b[MAXN];
map<pair<int,int>, int> M;
int K;

void search(Graph &G, int pair_node, int color) {
    int counter = 0;
    for(int nn : G[pair_node]) {
        counter++;
        if(counter==color)counter++;
        if(M[{nn,pair_node}] != 0 || M[{pair_node,nn}] != 0){
            counter--;
            continue;
        }
        M[{nn,pair_node}] = counter;
        M[{pair_node,nn}] = counter;
        search(G, nn, counter);
    }
}



int main(){
    cin >> N;
    pair<int,int> p = {0,0}; //{接点数,ノードの番号}s
    Graph G(N+1);
    
    rep(i,N-1) {
        cin >> a[i] >> b[i];
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
        if(G[a[i]].size() > p.first)p = {G[a[i]].size(),a[i]};
        if(G[b[i]].size() > p.first)p = {G[b[i]].size(),b[i]};
    }
    K = p.first;
    search(G, p.second, 0);
    cout << p.first << endl;


    rep(i,N-1) {
        cout << M[{a[i],b[i]}] << endl;
    }



    return 0;
}