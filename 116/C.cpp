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
    int N;cin >> N ;
    int h[101];
    rep(i,N)cin >> h[i];

    int height[101];
    memset(height,0,sizeof(height));
    height[101] = 101;
    int count = 0;
    while(1){
        bool first = true;
        for(int i=0;i<N;i++){
            if(h[i]>0){
                if(first){
                    count++;
                    first = false;
                }
                h[i]--;
            }else{
                first = true;
            }
        }
        bool ok = true;
        for(int i=0;i<N;i++){
            if(h[i]!=0)ok = false;
        }
        if(ok)break;
    }
    cout << count << endl;
    


    return 0;
}