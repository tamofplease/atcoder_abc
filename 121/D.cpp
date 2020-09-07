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
    ll A,B;cin >> A >> B;
    ll tmp = B;
    int bit = 0;
    ll ans = 0;
    ll ans2 = 0;
    A--;
    if(A%2==1){
        if(A==1)ans = 1;
        else ans = (A/2)%2;
    }else ans = A^(A/2)%2;

    if(B%2==1){
        if(B==1)ans2 = 1;
        else ans2 = (B/2)%2;
    }else ans2 = B^(B/2)%2;
    
    cout << ans << " " << ans2 << endl;
    
    ll fin= ans^ans2;
    cout << fin << endl;
    return 0;
}