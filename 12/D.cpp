#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
struct edge{
    int to,cost;
};
#define MAXN 320
#define INF 10000000
int d[MAXN][MAXN];
int main(){
    int N,M;
    cin >> N >> M;
    rep(i,N+1)rep(j,N+1)d[i][j] = INF;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    rep(k,N)rep(i,N)rep(j,N){
        if(i==j)d[i][j] = 0;
        d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
    }
    int Ma[MAXN];
    rep(i,N)Ma[i] = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            Ma[i] = max(Ma[i],d[i][j]);
        }
    }
    int t = INF;
    rep(i,N)t = min(t,Ma[i]);
    cout << t << endl;
    return 0;
}