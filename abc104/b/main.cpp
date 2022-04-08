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
    string s; cin >> s;
    int l = s.length();
    if(s[0] != 'A') {
        puts("WA");
        return 0;
    }
    int cnt = 0;
    for(int i=2;i<l-1;i++) {
        if(s[i] == 'C') cnt++;
    }
    if(cnt != 1) {
        puts("WA");
        return 0;
    }
    Rep(i, l-1) {
        if(s[i] == 'C') {
            continue;
        }
        if('a' <= s[i] && s[i] <= 'z') {
            continue;
        }
        puts("WA");
        return 0;
    }
    puts("AC");
    return 0;
}
