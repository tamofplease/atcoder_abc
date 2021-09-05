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
//素数判定
bool isPrime(int num){if(num<2)return false;else if(num==2)return true;else if(num==3)return true;else if(num%2==0)return false;else if (num % 3 == 0) return false;double sqrtNum=sqrt(num);for(int i=3;i<=sqrtNum;i+=2){if(num%i==0){return false;}}return true;}
// 約数全列挙
vector<ll> divisor(ll n){vector<ll>ret;for(ll i=1;i*i<=n;i++){if(n%i==0){ret.push_back(i);if(i*i!=n)ret.push_back(n/i);}}sort(ret.begin(),ret.end());return ret;}
int get_digit(ll N) {
  int digit = 0;
  while(N>0){
    N /=10;
    digit++;
  }
  return digit;
}

ll digit_number(int digit) {
  ll number = 9;
  rep(i,digit-1){
    number *= 10;
  }
  return number;
}
int point_number(int digit) {
  return (digit-1)/3;
}

ll least_number(int digit) {
  ll number = 1;
  rep(i,digit-1)number *= 10;
  return number;
}



int main(){
  ll N;cin >> N;
  ll ans = 0;
  int digit = get_digit(N)-1;
  for(int d=1;d<=digit;d++){
    ans += digit_number(d) * point_number(d);
  }
  digit++;
  ans += (N - least_number(digit) + 1) * point_number(digit);
  cout << ans << endl;
  



  return 0;
}
