#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> to(n+1);
    rep(i, m) {
        int a, b; cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    const int INF = 200001;
    queue<node> q;
    vector<int> minCosts(n+1, INF);
    vector<ll> routeNum(n+1, 0);
    q.push(1);
    minCosts[1] = 0;
    routeNum[1] = 1;
    while(!q.empty()) {
        int c = q.front();q.pop();
        int nxtCosts = minCosts[c] + 1;
        for(int nxt: to[c]) {
            if(minCosts[nxt] == INF) {
                q.push(nxt);
                minCosts[nxt] = nxtCosts;
                routeNum[nxt] = routeNum[c];
            } else if(minCosts[nxt] == nxtCosts) {
                routeNum[nxt] += routeNum[c];
                routeNum[nxt] %= MOD;
            }
        }
    }
    cout << routeNum[n] % MOD << endl;
    return 0;
}
