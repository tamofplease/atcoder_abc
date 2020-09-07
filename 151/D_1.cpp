#include <iostream>
#include <utility>
#include <queue>


typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
const int INF=100000000;
typedef pair<int,int> P;
#define MAXN 100
#define MAXM 100
char maze[MAXN][MAXM+1];
int N,M;
int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
int d[MAXN][MAXM+1];

int bfs(int sx,int sy,int gx,int gy){
    queue<P> q;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            d[i][j] = INF;
        }
    }
    q.push(P(sx,sy));
    d[sx][sy] = 0;
    while(q.size()){
        P p = q.front();
        
        q.pop();
        if(p.first == gx && p.second == gy)break;
        for(int i=0;i<4;i++){
        int nx = p.first+dx[i],ny = p.second+dy[i];
        //cout << p.first << p.second << " " << nx << ny << endl;
        if(0<=nx && nx<N&&0<=ny&&ny<M&&maze[nx][ny]!= '#'&&d[nx][ny]==INF){
            q.push(P(nx,ny));
            //cout <<  d[2][2] << endl;
            //cout << nx <<" "<< ny << endl;
            d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

int main(){
    cin >> N >> M;
    rep(i,N)rep(j,M){
        cin >> maze[i][j];
    }
    int ans = 0;
    rep(i,N)rep(j,M)rep(k,N)rep(l,M){
        int pto = bfs(i,j,k,l);
        if(maze[i][j]!='#'&&maze[k][l]!='#' && pto!=INF){
            ans = max(pto,ans);
        }
    }
    cout << ans << endl;
}