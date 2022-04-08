#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

string to_bin(ll n) {
    if(n < 2) return to_string(n);
    return to_bin(n>>1) + to_string(n%2);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, x; cin >> n >> x;
    string s; cin >> s;
    string ans = to_bin(x);
    for(char c : s) {
        if(c == 'U') ans.pop_back();
        if(c == 'L') ans += '0';
        if(c == 'R') ans += '1';
    }
    ll bin = 1;
    ll res = 0;
    for(int i = ans.length()-1;i>=0;i--) {
        int n = ans[i] - '0';
        res += n * bin;
        bin *= 2;
    }
    cout << res << endl;


    
    return 0;
}