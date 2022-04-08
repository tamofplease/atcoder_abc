#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int n, q; cin >> n >> q;
    vector<int> front(n+1), back(n+1);
    rep(i, q) {
        int type; cin >> type;
        if(type == 1) {
            int x, y; cin >> x >> y;
            back[x] = y;
            front[y] = x;
        } else if(type == 2) {
            int x, y; cin >> x >> y;
            back[x] = 0;
            front[y] = 0;
        } else {
            int x; cin >> x;
            int current = x;
            vector<int> ans;
            while(front[current] != 0) {
                current = front[current];
            }
            while(back[current] != 0) {
                ans.push_back(current);
                current = back[current];
            }
            ans.push_back(current);
            int siz = ans.size();
            cout << siz;
            rep(i, siz) {
                cout << " " << ans[i];
            }
            cout << endl;
        }

    }
    return 0;
}
