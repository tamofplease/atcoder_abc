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

bool sor(pair<ll,ll> &a, pair<ll,ll> &b){
    return a.first < b.first;
}
int main(){
    ll N,M;cin >> N >> M;
    const int MAXN = 100001;
    pair<ll,ll> P[MAXN];
    rep(i,N){
        cin >> P[i].first>> P[i].second;
    }

    sort(P,P+N,sor);

    ll count = 0;
    ll price = 0;
    // rep(i,N)cout << P[i].first << " ";
    // cout << endl;
    for(int i=0;i<N;i++){
        if(P[i].second + count <= M){
            count += P[i].second ;
            price += P[i].second * P[i].first;
        }else {
            price += P[i].first * (M-count);
            count = M;
        }
        if(count == M)break;
    }

    cout << price << endl;

    return 0;
}