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

    ll N,X; cin >> N >> X;

    string s[51];
    s[0] = "P";
    ll count[51];
    ll P[51],B[51];
    count[0] = 1;
    P[0] = 1;
    B[0] = 0;
    Rep(i,50){
        count[i] = count[i-1]*2 + 3;
        P[i]= P[i-1]*2+1;
        B[i] = B[i-1]+2;
    }
    
    ll ans = 0;



    cout << s[20] << endl;

    return 0;
}