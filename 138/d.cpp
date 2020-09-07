#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

using Graph = vector<vector<int> >;

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

int N,Q;
const int MAXN = 200000;
const int MAXQ = 200000;
int counter[MAXN+1] = {0};
bool checker[MAXN+1] = {false};


void search(Graph &G, int current_node, int value) {
    for(int nxt : G[current_node]) {
        if(!checker[nxt]){
            checker[nxt] = true;
            counter[nxt] += value;
            search(G,nxt,counter[nxt]);
        }
    }
}



int main() {
    cin >> N >> Q;
    Graph G(N+1);
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i,Q){
        int p,x;
        cin >> p >> x;
        counter[p] += x;
    }
    checker[1] = true;
    search(G, 1, counter[1]);
    Rep(i,N)cout << counter[i] << " ";
    cout << endl;



    return 0;
}