#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

struct handle{
    int fromx, fromy, tox, toy;
};

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>> table(h, vector<int>(w));
    rep(i, h) rep(j, w) {
        cin >> table[i][j];
    }
    int ans = 0;
    vector<handle> hand;
    
    rep(i, h) rep(j, w-1) {
        if(table[i][j] % 2 == 1) {
            table[i][j+1]++;
            table[i][j]--;
            hand.push_back({i+1,j+1,i+1,j+2});
            ans++;
        }
    }
    rep(i, h-1) {
        if(table[i][w-1] % 2 == 1) {
            table[i+1][w-1]++;
            table[i][w-1]--;
            hand.push_back({i+1, w, i+2, w});
            ans++;
        }
    }
    cout << ans << endl;
    rep(i, hand.size()) {
        cout << hand[i].fromx << " " << hand[i].fromy << " " << hand[i].tox << " " << hand[i].toy << endl;
    }

    return 0;
}
