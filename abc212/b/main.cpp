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
    if(s[0] == s[1] && s[2] == s[3] && s[1] == s[2]) {
        puts("Weak");
        return 0;
    }
    if(s[1] - '0' == (1 + (s[0] - '0')) % 10 && s[2] - '0' == (1 + (s[1] - '0')) % 10 && s[3] - '0' == (1 + (s[2] - '0')) % 10) {
        puts("Weak");
        return 0;
    }
    puts("Strong");

    return 0;
}
