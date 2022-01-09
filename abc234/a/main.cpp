#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int f(int x) {
    return x * x + 2 * x + 3;
}

int main(){
    int t; cin >> t;
    cout << f(f(f(t) + t) + f(f(t))) << endl;
    return 0;
}
