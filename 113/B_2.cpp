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
    int N;cin>> N;
    int T,A;cin >> T >> A;
    int H[1001];
    rep(i,N){
        cin >> H[i];
    }

    A *= 1000;

    T *= 1000;
    int tmp = INT32_MAX;
    int tmp_i = 0;
    rep(i,N){
        int tm = T - H[i]*6;
        if(abs(tm-A)<tmp){
            tmp = abs(tm-A);
            tmp_i = i;
        }
    }

    cout << tmp_i + 1 << endl;
    return 0;
}