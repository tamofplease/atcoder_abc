#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    set<string> se;
    rep(i, 4) {
        string s; cin >> s;
        se.insert(s);
    }
    if(se.size() == 4) {
        puts("Yes");
    } else{
        puts("No");
    }
    return 0;
}
