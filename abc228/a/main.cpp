#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int s,t,x;

int main(){
    cin >> s >> t >> x;
    if(s<t) {
        s<=x && x<t ? puts("Yes") : puts("No");
    } else {
        s <= x || x < t ? puts("Yes") : puts("No");
    }
    return 0;
}
