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
long long modinv(long long a, long long m=MOD) {long long b = m, u = 1, v = 0;while (b) {    long long t = a / b;    a -= t * b; swap(a, b);    u -= t * v; swap(u, v);}u %= m; if (u < 0) u += m;return u;}
//MODの割り算の際にa/＝b;をa *= modinv(b,MOD);とする。
int gcd(int a, int b){if (a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}
 
int main(){
    int N,M,X,Y;
    int x[101];int y[101];
    cin >> N >> M >> X >> Y;
    rep(i,N)cin >> x[i];
    rep(i,M)cin >> y[i];
    bool ok = false;
    int tmp = X+1;
    for(int i=tmp;i<=Y;i++){
        bool ok_n = true;
        rep(j,N){
            if(x[j] >= i){
                ok_n = false;
            }
        }
        bool ok_m = true;
        if(ok_n){
            rep(j,M){
                if(y[j] < i) {
                    ok_m = false;
                }
            }
        }
        if(ok_n && ok_m){
            // cout << i << endl; 
            ok = true;
            break;
        }
    }

    if(ok)cout << "No War" << endl;
    else cout << "War" << endl;
    return 0;
}