#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)

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

int const MAXN=100001;
int N,M;
int H[MAXN];
int A[MAXN],B[MAXN];

bool check[MAXN] = {false};

using Graph = vector<vector<int>>;

int ans = 0;

void search(Graph &G, int from) {
    for(int to : G[from]) {
        if(H[from] > H[to])check[to] = true;
        else check[from] = true;
    }
    if(!check[from])ans ++;
    else check[from] = true;
    return;
}

int main(){
    Graph G(MAXN);
    cin>>N>> M;

    Rep(i,N) cin >> H[i] ;
    Rep(i,M){
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    Rep(i,N){
        if(!check[i])search(G,i);
    }
    cout << ans << endl;

    return 0;
}