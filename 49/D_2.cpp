#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

struct UF{
    int par[200001];
    int runk[200001];
    void init(int n){
    for(int i=0;i<=n;i++){
        par[i] = i;
        runk[i] = 0;
    }
}
int find(int n){
    if(par[n] == n)return n;
    return par[n] = find(par[n]);
}
void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x==y)return;
    if(runk[x]<runk[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(runk[x]==runk[y])runk[x]++;
    }
}
bool issame(int x,int y){
    return find(x)== find(y);
}

};


int main(){
    UF uni1,uni2;
    int N,K,L;
    cin >> N >> K >> L;
    uni1.init(N);
    uni2.init(N);
    int p,q;
    for(int i=0;i<K;i++){
        cin >> p >> q;
        p--,q--;
        uni1.unite(p,q);
    }
    int r,s;
    for(int i=0;i<L;i++){
        cin >> r >> s;
        r--,s--;
        uni2.unite(r,s);
    }
    using pint = pair<int,int>;
    map<pint,int> ma;
    for(int i=0;i<N;i++){
        pint p(uni1.find(i),uni2.find(i));
        ma[p]++;
    }
    for(int i=0;i<N;i++){
        pint p(uni1.find(i),uni2.find(i));
        cout << ma[p] << ' ';
    }

    
    
    return 0;

}