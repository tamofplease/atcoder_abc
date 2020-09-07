#include <iostream>
#include <vector>

using namespace std;
int N;
#define MAX_N 100001
#define MAX_M 100001
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
            else color[i.to] = -color[current_node]
            col(G, i.to);
        }
    }
}

int main(){
    int N;cin >> N;
    memset(color, 0, N*sizeof(int));
    Graph G(N+1);
    rep(i,N){
        int a,b,c;
        cin >> a>> b >> c;
        G[a].push_back(edge(b,c));
        G[b].push_back(edge(a,c));
    }
    color[1] = 1;
    col(G,1);

    Rep(i,N)cout << color[i] << " ";




    return 0;
}
