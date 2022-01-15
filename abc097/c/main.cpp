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
    int k; cin >> k;
    int sl = s.length();
    set<string> ss;
    string tmp;
    rep(i, sl) {
        Rep(j, 5) {            
            tmp = s.substr(i, j);
            if(tmp.length() > 0) {
                ss.insert(tmp);
            }
        }
    }
    vector<string> v;
    for(string st: ss) {
        v.push_back(st);
    }
    sort(v.begin(), v.end());

    cout << v[k-1] << endl;

    return 0;
}
