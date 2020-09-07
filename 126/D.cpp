#include <bits/stdc++.h>

using namespace std;
int N;
#define MAX_N 100001
#define MAX_M 100001
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
struct edge{
    int to,weight;
    edge(int to,int weight):to(to),weight(weight){}
};
using Graph = vector<vector<edge>> ;


const int MAXN =  100000;
int color[MAXN];

void col(Graph &G, int current_node){
    for(edge i : G[current_node]){
        if(!color[i.to]){
            if(i.weight%2==0)color[i.to] = color[current_node];
            else color[i.to] = -color[current_node];
            col(G, i.to);
        }
    }
}

int main(){
    int N;cin >> N;
    memset(color, 0, N*sizeof(int));
    Graph G(N+1);
    rep(i,N-1){
        int a,b,c;
        cin >> a>> b >> c;
        G[a].push_back(edge(b,c));
        G[b].push_back(edge(a,c));
    }
    color[1] = 1;
    Rep(i,N)col(G,i);

    Rep(i,N){
        if(color[i]==1)cout << 0 << " ";
        else cout << 1 << " ";
        // cout << color[i] << " ";
    }
    cout << endl;




    return 0;
}
