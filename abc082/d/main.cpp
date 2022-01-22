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
    string s; cin >> s;
    int x, y; cin >> x >> y;
    vector<int> horizontal, vertical;
    int tmp = 0;
    bool straight = s[0] == 'F';
    bool isHorizontal = true;
    for(char c : s) {
        if(c == 'F') {
            tmp++;
        } else {
            if(isHorizontal && tmp != 0) horizontal.push_back(tmp);
            else if(tmp !=0) vertical.push_back(tmp);
            tmp = 0;
            isHorizontal = !isHorizontal;
        }
    }
    if(tmp != 0) {
        isHorizontal ? horizontal.push_back(tmp) : vertical.push_back(tmp);
    }
    int hs = (int)horizontal.size(); int vs = (int)vertical.size();
    vector<set<int>> dh(hs+1, set<int>()), dv(vs+1, set<int>());
    dh[0].insert(0); dv[0].insert(0);
    tmp = 0;
    for(int h : horizontal) {
        for(auto it : dh[tmp]) {
                dh[tmp + 1].insert(it+h);
            if(tmp!=0 || !straight) {
                dh[tmp+1].insert(it-h);
            }
        }
        tmp++;
    }
    tmp = 0;
    for(int v : vertical) {
        for(auto it : dv[tmp]) {
            dv[tmp+1].insert(it+v);
            dv[tmp+1].insert(it-v);
        }
        tmp++;
    }
    if(dh[hs].find(x) != dh[hs].end() && dv[vs].find(y) != dv[vs].end()) puts("Yes");
    else puts("No");
    return 0;
}
