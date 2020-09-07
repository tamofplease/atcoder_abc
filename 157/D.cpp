#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using Graph = vector<vector<int> >;

#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)

const int MAXN = 100001;
int counter[MAXN] = {0};


void bfs(Graph &Friend, Graph &Node ,int basenode, int curnode, int node[]) {
  for(int i : Friend[curnode]) {
    if(node[i] != 1) {
      if(node[i] == 0)counter[basenode]++;
      Node[basenode].push_back(i);
      node[i] = 1;
      bfs(Friend, Node, basenode, i, node);
    }
  }
}

int main() {
  int N,M,K;
  cin >> N >> M >> K;
  const int n = N+1;
  Graph Friend(N+1);
  Graph Enemy(N+1);
  Graph Node(N+1);

  rep(i,M) {
    int a,b;cin >> a >> b;
    Friend[a].push_back(b);
    Friend[b].push_back(a);
  }

  rep(i,K) {
    int c,d;cin >> c >> d;
    Enemy[c].push_back(d);
    Enemy[d].push_back(c);
  }
  int node[n] = {0};
  int label[N]= {0};
  map<int,int> ma = {};
  Rep(i,N) {
    
    for(int j : Friend[i])node[j] = -1;
    for(int j : Enemy[i])node[j] = -1;
    if(!label[i]){bfs(Friend,Node, i,i, node,label);
    cout << counter[i] - 1 <<" ";
  }
  cout << endl;

  return 0;
}