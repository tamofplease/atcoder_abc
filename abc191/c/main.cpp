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
long long modinv(long long a,long long m=MOD){long long b=m,u=1,v=0;while(b){long long t=a/b;a-=t*b;swap(a,b);u-=t*v;swap(u,v);}u%=m;if(u<0)u+=m;return u;}
//MODの割り算の際にa/＝b;をa *= modinv(b,MOD);とする。
int gcd(int a, int b){if (a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}
#define INF (1<<30-1)
#define LINF (1LL<<60)
bool isPrime(int num){if(num<2)return false;else if(num==2)return true;else if(num==3)return true;else if(num%2==0)return false;else if (num % 3 == 0) return false;double sqrtNum=sqrt(num);for(int i=3;i<=sqrtNum;i+=2){if(num%i==0){return false;}}return true;}
#define MAXH 12
bool check[12][12];
char table[MAXH][MAXH];
int count = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
int p[3] = { -1, 0, 1};
int H,W;
int ans;
bool valid(int x, int y) {
  if(x <= W && x > 0 && y <= H && y > 0) return true;
  else return false;
}
void search(int x, int y){
  if(table[y][x] == '#'){
    bool tl = table[y+1][x-1] == '#';
    bool tc = table[y+1][x] == '#';
    bool tr = table[y+1][x+1] == '#';
    bool cl = table[y][x-1] == '#';
    bool cr = table[y][x+1] == '#';
    bool br = table[y-1][x+1] == '#';
    bool bc = table[y-1][x] == '#';
    bool bl = table[y-1][x-1] == '#';
    if((!tc && !tl && !cl) || (!tl && tc && cl))ans++;
    if((!tr && !tc && !cr) || (!tr && tc && cr))ans++;
    if((!bl && !bc && !cl) || (!bl && bc && cl))ans++;
    if((!br && !bc && !cr) || (!br && bc && cr))ans++;
  }
  check[y][x] = true;

  for(int i=0;i<4;i++){
    int nextx = x + dx[i];
    int nexty = y + dy[i];
    if(valid(nextx,nexty) && !check[nexty][nextx])search(nextx, nexty);
  }
}
int main(){
  memset(check, false, sizeof(check));
  cin >> H >> W;
  memset(table, '.', sizeof(table));
  Rep(i,H)Rep(j,W)cin >> table[i][j];
  search(1,1);
  cout << ans << endl;  
  return 0;
}
