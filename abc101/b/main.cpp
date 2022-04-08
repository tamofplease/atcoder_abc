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
    ll n; cin >> n;
    string s = to_string(n);
    int tm = 0;
    for(char c : s) {
        tm += c - '0';
    }
    (n%tm)?puts("No"):puts("Yes");
    return 0;
}
