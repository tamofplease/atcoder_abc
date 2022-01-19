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
    int h, w; cin >> h >> w;
    vector<string> table(h);
    rep(i, h) cin >> table[i];
    vector<vector<int>> score(h, vector<int>(w, 2501));
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(1, make_pair(0,0)));
    int remain = 0;
    rep(i, h) rep(j, w) {
        if(table[i][j] == '.') remain++;
    }
    score[0][0] = 1;
    int x[4] = {0,0,-1,1};
    int y[4] = {-1,1,0,0};
    while(!q.empty()) {
        pair<int, pair<int, int>> cur = q.front(); q.pop();
        int cost = cur.first;
        pair<int, int> dim = cur.second;
        rep(i, 4) {
            int nx = dim.second + x[i];
            int ny = dim.first + y[i];
            if(0 <= nx && nx < w && 0 <= ny && ny < h && table[ny][nx] != '#') {
                if(score[ny][nx] > cost + 1) {
                    q.push(make_pair(cost+1, make_pair(ny, nx)));
                    score[ny][nx] = cost+1;
                }
            }
        }
    }
    if(score[h-1][w-1] > 2500) {
        cout << -1 << endl;
        return 0;
    }
    cout << remain - score[h-1][w-1] << endl;
    return 0;
}
