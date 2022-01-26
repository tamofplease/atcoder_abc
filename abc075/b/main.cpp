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
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '#') {
                cout << "#";
                continue;
            }
            int boms = 0;
            for(int dx=-1;dx<=1;dx++) for(int dy=-1;dy<=1;dy++) {
                if(0<=i+dy && i+dy < h && 0<=j+dx && j+dx<=w){
                    if(s[i+dy][j+dx] == '#')boms++;
                }
            }
            cout << boms;
        }
        cout << endl;
    }


    return 0;
}
