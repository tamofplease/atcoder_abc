#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    /// 9 8 3 7 2
    /// 1 6 2 9 5
    vector<vector<int>> to(n*2);
    rep(i,n-1) {
        if(abs(a[i] - a[i+1]) <= k) to[i].push_back(i+1);
        if(abs(a[i] - b[i+1]) <= k) to[i].push_back(n+i+1);
        if(abs(b[i] - a[i+1]) <= k) to[n+i].push_back(i+1);
        if(abs(b[i] - b[i+1]) <= k) to[n+i].push_back(n+i+1);
    }

    map<int, bool> memo;

    auto search = [&](auto f, int cur) -> bool {
        if(memo.find(cur) != memo.end()) return memo[cur];
        if(cur == n-1 || cur == 2*n-1) return true;
        for(int nxt : to[cur]) {
            memo[nxt] = f(f, nxt);
            if(memo[nxt]) return memo[nxt];
        }
        return false;
    };

    if(search(search, 0) || search(search, n)) {
        puts("Yes"); 
    } else {
        puts("No");
    }

    return 0;
}