#include <queue>
#include <iostream>
 
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
 
struct edge{
    int to,weight;
    edge(int to,int weight):to(to),weight(weight){}
};
struct place {
    int wi,he;
    place(int wi,int he):wi(wi),he(he){}
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
const int MAXH = 3001;
const int MAXW = 3001;
int C_h,C_w;
int D_h,D_w;
char S[MAXH][MAXW];
int H,W;
int maze[MAXH][MAXW]; //到達できる場所
 
void show_maze(){
    rep(i,H){
        rep(j,W){
            cout << maze[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
 
int main(){
    cin >> H >> W;
    cin >> C_h >> C_w;
    cin >> D_h >> D_w;
 
    rep(i,H)rep(j,W){
        cin >> S[i][j];
    }
 
    rep(i,MAXH)rep(j,MAXW){
        maze[i][j] = -1;
    }
 
    queue<pair<int,int> > Q;
 
    Q.push(make_pair(C_h-1,C_w-1));
    maze[C_h-1][C_w-1] = 0;
 
 
    int x_dir[4]={1,-1,0,0};
    int y_dir[4]={0,0,1,-1};
    int counter = 0;
    while(1){
        while(!Q.empty()){
            pair<int,int> current = Q.front();
            Q.pop();
            rep(i,4){
                int y = current.first + y_dir[i];
                int x = current.second + x_dir[i];
                if(maze[y][x]==-1 && y>=0 && y<H && x>=0 && x<W && S[y][x]=='.'){
                    maze[y][x] = counter;
                    Q.push(make_pair(y,x));
                }
            }
        }
        counter++;
        rep(i,H)rep(j,W){
            if(maze[i][j]==(counter-1)){
                for(int k=-2;k<=2;k++){
                    for(int l=-2;l<=2;l++){
                        if((k==1 && l==0 )|| (k==-1 && l==0 )|| (k==0 && l==1) || (k==0 && l==-1) || (k==0 && l==0)){ 
                        }else{
                            int x = j+l;
                            int y = i+k;
                            if(y>=0 && y<H && x>=0 && x<W && maze[y][x]==-1 && S[y][x]=='.'){
                                maze[y][x] = counter;
                                Q.push(make_pair(y,x));
                            }
                        }
                    }
                }
            }
        }
        if(Q.empty())break;
    }
    
 
 
    cout << maze[D_h-1][D_w-1] << endl;
 
    // show_maze();
 
 
    return 0;
}