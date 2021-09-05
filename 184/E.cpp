#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
struct edge{
  int to,weight;
  edge(int to,int weight):to(to),weight(weight){}
};
using Graph = vector<vector<int>> ;
using GraphEdge = vector<vector<int>> ;
long long modinv(long long a, long long m=MOD) {long long b = m, u = 1, v = 0;while (b) {    long long t = a / b;    a -= t * b; swap(a, b);    u -= t * v; swap(u, v);}u %= m; if (u < 0) u += m;return u;}
//MODの割り算の際にa/＝b;をa *= modinv(b,MOD);とする。
int gcd(int a, int b){if (a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}

int H,W;
#define MAXH 2000
#define MAXW 2000
int g_x, g_y;
char stage[MAXH][MAXW];
int xd[4] = {1,-1,0,0};
int yd[4] = {0,0,1,-1};
int checker[MAXH][MAXW];

map<char, pair<pair<int,int>, pair<int,int> > > ma; 



void start(int x, int y, int current_cost){
  checker[y][x] = current_cost;
  for(int i=0;i<4;i++){
    int dx = xd[i]; int dy = yd[i];
    int new_x = x + dx;
    int new_y = y + dy;
    if(new_x < W && new_x >= 0 && new_y < H && new_y >= 0){
      if(stage[new_y][new_x] != '#'){
        if(checker[new_y][new_x] > current_cost + 1) start(new_x, new_y, current_cost + 1);
      }
    }
  }
  if(stage[y][x] != 'S' && stage[y][x] != 'G' && stage[y][x] != '#' && stage[y][x] != '.'){
    pair<int,int> now = make_pair(y,x);
    int warp_y;
    int warp_x;
    if(ma[stage[y][x]].first.second == now.second && ma[stage[y][x]].first.first == now.first){
      pair<int,int> warp = ma[stage[y][x]].second;
      warp_y = warp.first;
      warp_x = warp.second;
    }else{
      pair<int,int> warp = ma[stage[y][x]].first;
      warp_y = warp.first;
      warp_x = warp.second;
    }
    if(checker[warp_y][warp_x] > current_cost + 1)start(warp_x, warp_y, current_cost + 1);
  }
}

int main(){
  rep(i,2000)rep(j,2000)checker[i][j] = 4000001;
  map<char,int> mapo;
  cin >> H >> W;
  int s_x, s_y;
  rep(i,H)rep(j,W){
    cin >> stage[i][j];
    if(stage[i][j] == 'S') {
      s_x = j;
      s_y = i;
    }else if(stage[i][j] == 'G'){
      g_x = j;
      g_y = i;
    }else if(stage[i][j] != '.'){
      if(mapo[stage[i][j]]==0){
        ma[stage[i][j]].first = make_pair(i,j);
        mapo[stage[i][j]]=1;
      }else{
        ma[stage[i][j]].second = make_pair(i,j);
      }
      
    }
  }

  start(s_x, s_y, 0);
  if(checker[g_y][g_x] == 4000001)cout << -1 << endl;
  else cout << checker[g_y][g_x] << endl;

  return 0;
}