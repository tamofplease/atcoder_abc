#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    string s; cin >> s;
    int len = s.length();
    if(s.substr(len-2, len) == "er") {
        puts("er");
    } else {
        puts("ist");
    }
    return 0;
}
