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

bool sor(const int &a, const int &b){
    return a>b;
}
int main(){
    int me[5];
    int ma = 10;
    int count = 0;
    rep(i,5)cin >> me[i];
    rep(i,5){
        if(me[i]%10==0){
            count+=me[i];
        }else{
            if(me[i]>100){
                count+=((me[i]/10)+1)*10;
            }else if(me[i]>10){
                count+=((me[i]/10)+1)*10;
            }else {
                count+=10;
            }
        }
        
        if(me[i]>=100){
            if(me[i]%10!= 0 && (me[i]%10) < ma){
                ma = me[i]%10;
            }
        }else if(me[i]>=10){
            if(me[i]%10 != 0 && (me[i]%10) < ma){
                ma = me[i]%10;
            }
        }else if(me[i]<ma){
            ma = me[i];
        }
    } 

    cout << count-(10-ma) << endl;
    return 0;
}