#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int n, a, x, y;
    cin >> n >> a >> x >> y;    
    if (n > a){
        cout << a * x + (n - a) * y << endl;
    } else {
        cout << n * x << endl;
    }
    return 0;
}
