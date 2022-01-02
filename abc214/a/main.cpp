#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int n; cin >> n;
    if(n < 126) {
        puts("4");
    } else if(n > 211) {
        puts("8");
    } else {
        puts("6");
    }
    return 0;
}
