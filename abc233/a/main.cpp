#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int main(){
    int x, y; cin >> x >> y;
    int diff = y - x;
    if(diff < 1) {
        cout << 0 << endl;
        return 0;
    }
    if(diff % 10 == 0) {
        cout << diff / 10 << endl;
    } else {
        cout << (diff / 10) + 1 << endl;
    }
    return 0;
}
