#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct UF{
    vector<int> par;
    UF(int n):par(n,-1){}
    void init(int n){
        par.assign(n,-1);
    }
    int root(int x){
        if(par[x]<0)return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x,int y){
        return root(x)==root(y);
    }

    bool merge(int x,int y){
        x = root(x);
        y = root(y);
        if(x==y)return ;
        if(par[x]>par[y])swap(x,y);
        par[x]+= par[y];
        par[y] = x;
    }
    int size(int x){
        return -par[root(x)];
    }
};
int main(){
    int N,K,L;cin >> N >> K >> L;
    UF uf1(N),uf2(N);
    for(int i=0;i<K;i++){
        int a,b;cin >> a,b;a--,b--;
        uf1.merge(a,b);
    }
    for(int i=0;i<L;i++){
        int a,b;cin >> a >> b;a--,b--;
        uf2.merge(a,b);
    }
    using pint = pair<int,int>;
    map<pint,int> ma;
    for(int v = 0;v<N;v++){
        pint p(uf1.root(v),uf2.root(v));
        ma[p]++;
    }
    for(int v=0;v<N;v++){
        pint p(uf1.root(v),uf2.root(v));
        cout << ma[p] << " ";
    }
}
