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
long long modinv(long long a, long long m=MOD) {long long b = m, u = 1, v = 0;while(b){long long t=a/b;a-=t*b;swap(a,b);u-=t*v;swap(u,v);}u%=m;if(u<0)u+=m;return u;}
//MODの割り算の際にa/＝b;をa *= modinv(b,MOD);とする。
int gcd(int a, int b){if (a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}
#define INF (1<<30-1)
#define LINF (1LL<<60)
bool isPrime(int num){if(num<2)return false;else if(num==2)return true;else if(num==3)return true;else if(num%2==0)return false;else if (num % 3 == 0) return false;double sqrtNum=sqrt(num);for(int i=3;i<=sqrtNum;i+=2){if(num%i==0){return false;}}return true;}

double probability[10][10]; // i,jを引き当てる確率
int number[10];

string S,T;
bool calcWinner(int a, int b) { // 高橋くんがA, 青木がBを引いた時に高橋くんが勝つならtrueを返す
  int Ta[10];
  int Ao[10];
  Rep(i,9){
    Ta[i] = 0;
    Ao[i] = 0;
  }
  rep(i,4){
    Ta[S[i] - '0'] += 1;
    Ao[T[i] - '0'] += 1;
  }
  Ta[a]++;Ao[b]++;
  ll ansTa = 0;
  ll ansAo = 0;
  Rep(i,9) {
    ansTa += i * pow(10,Ta[i]);
    ansAo += i * pow(10,Ao[i]);
  }
  return ansTa > ansAo;
}

int main(){
  int K;cin >> K;
  cin >> S >> T;

  Rep(i,9){
    number[i] = K;
  }

  rep(i,4){
    number[S[i] - '0'] -= 1;
    number[T[i] - '0'] -= 1;
  }

  Rep(i,9)Rep(j,9){
    probability[i][j] = (double)number[i] / ((9 * K) - 8);
    number[i]--;
    probability[i][j] *= (double)number[j] / ((9 * K) - 9);
    number[i]++;
  }

  double ans = 0;

  Rep(i,9)Rep(j,9){
    if(calcWinner(i,j)){
      ans += probability[i][j];
    }
  }

  printf("%0.20f\n", ans);

  return 0;
}
