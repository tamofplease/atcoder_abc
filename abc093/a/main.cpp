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
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    set<char> se, re;
    rep(i, 3) {
        se.insert(s[i]);
    }
    if (se.size() == 3 && se.find('a') != se.end() && se.find('b') != se.end() && se.find('c') != se.end()) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}
