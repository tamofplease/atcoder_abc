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

int jyun[100000000];
int N;
const ll maxN = 1000000001;
void list_tfs(vector<int> &G, ll tmp) {
    G.push_back(tmp);
    if(tmp*10+3<=N)list_tfs(G,(tmp*10+3));
    if(tmp*10+5<=N)list_tfs(G,(tmp*10+5));
    if(tmp*10+7<=N)list_tfs(G,(tmp*10+7));
    return;
}

int main(){
    cin >> N;
    vector<int> G;
    int num = 0;
    list_tfs(G,3);
    list_tfs(G,5);
    list_tfs(G,7);
    sort(G.begin(),G.end());
    int len = G.size();
    int count = 0;
    rep(i,len){
        int tmp = G[i];
        bool three=false, five=false, seven = false;
        while(tmp > 0){
            int tm = tmp%10;
            tmp/=10;
            if(tm==3)three=true;
            if(tm==5)five=true;
            if(tm==7)seven=true;
        }
        if(three && five && seven){
            count++;
        }
    }

    cout << count << endl;

    
    return 0;
}