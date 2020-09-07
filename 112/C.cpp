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
    int N;cin >> N;
    int x[101],y[101];
    int h[101];
    rep(i,N){
        cin >> x[i] >> y[i] >> h[i];
    }

    int C[101][101];
    bool ok[101][101];
    int ans_x,ans_y;
    int ans;
    int tx,ty,ta;
    memset(ok,true,sizeof(ok));
    memset(C, -1, sizeof(C));
    int count = 0;
    rep(i,N){
        while(h[i]==0)i++;
        rep(C_x,101){
            rep(C_y,101){
                tx = x[i];
                ty = y[i];
                ta = h[i];
                count++;
                int tmp =  h[i] + abs(x[i]-C_x) + abs(y[i]-C_y);
                if(C[C_x][C_y] == -1){
                    C[C_x][C_y]  = tmp;
                }
                else if(C[C_x][C_y] == tmp && ok[C_x][C_y]){
                    ans_x = C_x, ans_y = C_y;
                    ans = tmp;
                }else{
                    ok[C_x][C_y] = false;
                }
            }
            
        }
    }

    if(count==1){
        cout << tx << " " << ty << " " << ta <<
    }

    cout << ans_x << " " << ans_y << " " << ans << endl;

    return 0;
}