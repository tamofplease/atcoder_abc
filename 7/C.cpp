#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Graph = vector<vector<int> >;
using Graphc = vector<vector<char> >;
#define INF 100000000
int R,C;
using p = pair<int,int>;
int sy,sx,gy,gx;
queue<p> q;
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
/*void search(const Graphc &c,Graph hint,int i,int j){
    for(int r=0;r<4;r++){
        int nx = i+dx[r];
        int ny = j+dy[r];
        if(nx<R&&nx>=0&&ny>=0&&ny<C&&hint[nx][ny]==INF&&c[nx][ny]!='#'){
            q.push(p(nx,ny));
            hint[nx][ny] = hint[i][j] + 1;
        }
    }
}*/

int main(){
    cin >> R >> C >> sy >> sx >> gy >> gx;
    sy -=1;sx-=1;
    gy-=1;gx-=1;
    Graphc c;
    Graph hint;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> c[i][j];
            hint[i][j] = INF;
        }
    }/*
    q.push(p(sx,sy));
    hint[sx][sy] = 0;
    while(!q.empty()){
        p x = q.front();
        if(x.first==gx&&x.second == gy)break;
        q.pop();
        //search(c,hint,x.first,x.second);
    }

    cout << hint[gx][gy] << endl;
    */

}