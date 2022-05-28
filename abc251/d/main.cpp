#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    vector<int> ans;
    int tmp = 1;
    Rep(i, 3) {
        Rep(j, 99) {
            int cur = j * tmp;
            if (cur > w) {
                break;
            }
            ans.push_back(j * tmp);
        }
        tmp *= 100;
    }
    if (w == 1000000) {
        ans.push_back(1000000);
    }
    int n = ans.size();
    cout << n << endl;
    rep(i, n) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}