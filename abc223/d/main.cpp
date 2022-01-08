#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> to(n);
    vector<int> in(n);
    rep(i, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        in[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<bool> decided(n);
    rep(i, n) {
        if(in[i] == 0) pq.push(i);
    }
    if(pq.empty()) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    while(!pq.empty()) {
        int cur = pq.top(); pq.pop();
        ans.push_back(cur);
        for(int nxt : to[cur]) {
            if(decided[nxt]) {
                cout << -1 << endl;
                return 0;
            }
            in[nxt]--;
            if(in[nxt] == 0) {
                decided[nxt] = true;
                pq.push(nxt);
            }
        }
    }

    if(ans.size() != n) {
        cout << -1 << endl;
        return 0;
    }
    
    cout << 1 + ans[0];
    Rep(i, n-1) {
        cout << " " <<  1 + ans[i];
    }
    cout << endl;

    return 0;
}
