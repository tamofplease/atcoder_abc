#include <iostream>
#include <vector>

using namespace std;

int N,M,T;
#define rep(i,n) for(int i=0;i<n;i++)
vector<int> V(N);
struct edge{
    int to,cost;
};
#define MAXN 100001
int A[MAXN];
int main(){
    vector<edge> Ed[MAXN];
    cin >> N >> M >> T;
    rep(i,N)cin >> A[i];
    rep(i,M){
        int a,b,c;
        cin >> a >> b >> c;
        edge e;e.to = b,e.cost = c;
        Ed[a].push_back(e);
    }
    
    return 0;
}   