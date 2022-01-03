#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int a,b;
int main(){
    cin >> a >> b;
    if(a == 0) {
        puts("Silver");
    } else if(b == 0) {
        puts("Gold");
    } else {
        puts("Alloy");
    }
    return 0;
}
