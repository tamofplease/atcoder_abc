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

    int N,Q;cin >> N >> Q;
    string s;cin >> s;
    int len = s.length();
    const int MAXN = 100001;
    int tm[MAXN];
    tm[0] = 0;
    Rep(i,len){
        tm[i] = tm[i-1];
        if(s[i-1]=='A' && s[i]=='C')tm[i]++;
    }
    const int MAXQ = 100001;
    int l[MAXQ],r[MAXQ];
    rep(i,Q){
        cin >> l[i]>> r[i];
    }

    rep(i,Q){
        cout << tm[r[i]-1] - tm[l[i]-1] << endl;
    }




    return 0;
}