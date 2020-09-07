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
    string S;cin >> S;
    int y = 0, m = 0, d = 0;
    rep(i,4){
        y += S[i]-'0';
        y*=10;
    }
    y/=10;
    for(int i=5;i<=6;i++){
        m += S[i]-'0';
        m *= 10;
    }
    for(int i=8;i<=9;i++){
        d += S[i] - '0';
        d *= 10;
    }
    d /= 10;
    m /=10;

    if(y < 2019)cout << "Heisei" << endl;
    else if(y == 2019 && m < 4)cout << "Heisei" << endl;
    else if(y==2019 && m == 4 && d <= 30)cout << "Heisei" << endl;
    else cout << "TBD" << endl;

    return 0;
}