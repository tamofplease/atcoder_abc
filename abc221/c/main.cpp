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
    string n; cin >> n;
    sort(ALL(n));
    int nl = n.length();
    int ans = 0;
    do {
        Rep(i, nl-1) {
            string l = n.substr(0, i);
            string r= n.substr(i, nl);
            if(l[0] == 0 || r[0] == 0) continue;
            ans = max(stoi(l) * stoi(r), ans);
        }
    } while(next_permutation(ALL(n)));
    cout << ans << endl;
    return 0;
}
