#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define MAXN 100001
int N;
int par[MAXN];

struct node{
    int x,y,name;
};
node N1[MAXN];
node N2[MAXN];
struct edge{
    int from,to,cost;
};
bool comp(const node& a,const node& b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
bool comp2(const node& a,const node& b){
    if(a.y==b.y)return a.x<b.x;
    return a.y<b.y;
}
void init(int a){
    rep(i,N)par[i] = -1;
}
int find(int s){
    if(par[s]<0)return s;
    return par[s] = find(par[s]);
}
void unite(int s,int t){
    s = find(s),t = find(t);
    if(s==t)return;
    if(par[s]>par[t])swap(s,t);
    par[s] += par[t];
    par[t] = s;
}
bool issame(int s,int t){
    return find(s) == find(t);
}
bool sor(const edge& a,const edge& b){
    return a.cost<b.cost;
}
int main(){
    cin >> N;
    rep(i,N){
        int xx,yy;cin >> xx >> yy;
        N1[i] = (node){xx,yy,i};
        N2[i] = (node){xx,yy,i};
    }
    ll cost = 0;
    sort(N1,N1+N,comp);
    
    edge cos[MAXN*2];
    rep(i,N-1){
        cos[i] = (edge){N1[i].name,N1[i+1].name,abs(N1[i].x-N1[i+1].x)};
    }   
    sort(N2,N2+N,comp2);
    rep(i,N-1){
        cos[i+N-1] = (edge){N2[i].name,N2[i+1].name,abs(N2[i].y-N2[i+1].y)};
    }
    
    sort(cos,cos+2*N-2,sor);
    init(N);
    rep(i,2*N-2){
        if(!issame(cos[i].from,cos[i].to)){
            cost += cos[i].cost;
            cout << cos[i].from <<' '<< cos[i].to << ' '  << cos[i].cost << endl;
            unite(cos[i].from,cos[i].to);
        }
    }
    cout << cost << endl;
    return 0;

}