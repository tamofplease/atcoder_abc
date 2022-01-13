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
    int r; cin >> r;
    if(r>=2800) {
        puts("AGC");
    } else if(r>=1200) {
        puts("ARC");
    } else {
        puts("ABC");
    }
    return 0;
}
