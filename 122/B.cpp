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


bool contain(char a){
    string test = "ATGC";
    rep(i,4){
        if(a==test[i])return true;
    }
    return false;
}
int main(){

    string s;cin >> s;
    int len = s.length();
    int counter = 0;
    int ans = 0;
    rep(i,len){
       if(contain(s[i])){
            counter++;
            ans = max(ans,counter);
       }else {
           counter = 0;
       }
    }

    cout << ans << endl;
    return 0;
}