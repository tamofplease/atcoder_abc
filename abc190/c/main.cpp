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
#define MAXM 110
int A[MAXM],B[MAXM];
#define MAXK 17
int C[MAXK],D[MAXK];
int dish[MAXM];
int N,M,K;
int countNumber(){
  int number = 0;
  rep(i,M){
    if(dish[A[i]] && dish[B[i]]) number++;
  }
  return number;
}

int main(){
  int ans = 0;
  memset(dish, 0, sizeof(dish));
  cin >> N >> M;
  rep(i,M)cin >> A[i] >> B[i];
  cin >> K;
  rep(i,K)cin >> C[i] >> D[i];
  for(int i=0;i<(1<<K);i++){
    for(int bit=0;bit<=K;bit++){
      if((i>>bit) & 1){
        dish[C[bit]] = 1;
      }else{
        dish[D[bit]] = 1;
      }
    }
    ans = max(ans, countNumber());
    memset(dish, 0, sizeof(dish));
  }
  cout << ans << endl;
  return 0;
}
