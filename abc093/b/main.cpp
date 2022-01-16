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
    int a, b, k; cin >> a >> b >> k;
    set<int> ans;
    for(int i=a;i<min(a+k, b); i++) {
        ans.insert(i);
    }
    for(int i=max(a, b-k+1);i<=b;i++) {
        ans.insert(i);
    }
    for(int val: ans) {
        cout << val << endl;
    }
    return 0;
}
