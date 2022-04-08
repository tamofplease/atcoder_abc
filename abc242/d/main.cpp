#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int make_bin(ll k) {// zero, one
    int one = 0;
    while(k > 0) {
        if(k&1) one++;
        k = (k>>1);
    }
    return one;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    int q; cin >> q;

    ///0: a b c
    ///1: b c c a a b
    ///2: c a a b a b b c b c c a
    /// t, k = (2, 4) => b
    
    string tmp = "ABC";
    map<char, int> ma { {'A', 0}, {'B', 1}, {'C', 2},};

    rep(i,q) {
        ll t, k; cin >> t >> k;
        k--;
        char root = s[0]; // a, b, or c
        ll border = 1;
        for(int i=0;i<t;i++) {
            border *= 2;
            if(border > k) break;
        }
        if(border <= k) {
            root = s[floor(k/border)];
            k%=border;
        }
        ll df = (t + make_bin(k)) % 3;
        root = tmp[(ma[root]+df)%3];
        cout << root << endl;
    }
    return 0;
}