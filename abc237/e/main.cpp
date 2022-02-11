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
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    map<int, vector<int>> ma;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    rep(i, m) {
        int from, to; cin >> from >> to;
        if(ma.find(from) == ma.end()) {
            ma[from] = vector<int>();
        }
        ma[from].push_back(to);
        if(ma.find(to) == ma.end()) {
            ma[to] = vector<int>();
        }
        ma[to].push_back(from);
    }
    map<int, int> score;
    score[h[0]] = 0;
    queue<int> q;
    q.push(h[0]);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int next: ma[cur]) {
            if(score.find(next) == score.end()) {
                if(cur > next) score[next] = score[cur] + (cur - next);
                else score[next] = score[cur] + 2 * (cur - next);
            } else {
                if(cur > next) score[next] = max(score[next], score[cur] + (cur - next));
                else score[next] = max(score[cur] +  2 * (cur - next), score[next]);
            }
        }
    }
    int ans = 0;
    for(auto const& [key, val] : score) {
        ans = max(val, ans);
    }
    cout << ans << endl;


    return 0;
}
