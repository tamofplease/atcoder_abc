#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)

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


const int MAXN=100001;
int N,M,K;

using Graph = vector<vector<int> >;

map<int,int> label;
int numberling[MAXN] = {0};
int Node[MAXN] = {0};
int ans[MAXN] = {0};

void bps(Graph &Friend, Graph &Enemy, int  current_person, int counter) {
  numberling[current_person] = counter;
  label[counter]++;
  for(int tm : Friend[current_person]) {
    Node[current_person]++;
    if(numberling[tm]==0){
      bps(Friend,Enemy,tm,counter);
    }
  }
  return;
}

int main(){
  cin >> N >> M >> K;
  Graph Friend(N+1);
  Graph Enemy(N+1);
  rep(i,M){
    int a,b;cin >> a >> b;
    Friend[a].push_back(b);
    Friend[b].push_back(a);
  }
  int c[MAXN];
  int d[MAXN];
  rep(i,K) {
    cin >> c[i] >> d[i];
  }
  int counter = 0;
  Rep(i,N) {
    if(!numberling[i]){
      counter++;
      bps(Friend, Enemy, i, counter);
    }
  }

  Rep(i,N) {
    ans[i] = label[numberling[i]];
  }
  
  rep(i,K) {
    if(numberling[c[i]] == numberling[d[i]]) {
      ans[c[i]]--;
      ans[d[i]]--;
    }
  }

  rep(i,N){
    cout << ans[i+1] - 1 - Node[i+1] << " ";
  }
  cout << endl;
  return 0;

}