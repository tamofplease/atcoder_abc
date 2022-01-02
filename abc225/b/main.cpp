#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main() {
    int n; cin >> n;
    vector<set<int>> vec(n);
    rep(i, n-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        vec[a].insert(b);
        vec[b].insert(a);
    }
    rep(i, n) {
        if(vec[i].size() == (long unsigned int) n-1) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
