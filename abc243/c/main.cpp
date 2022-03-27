#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

bool hasCollitionHappen(vector<pair<int, char>> v) {
    if(v.size() == 0) return false;
    int left = INT32_MAX; /// most left side person who look right
    int right = INT32_MIN; /// most right side person who look left;
    for(pair<int,char> p : v) {
        if(p.second == 'L') {
            right = max(p.first, right);
        } else {
            left = min(p.first, left);
        }
    }
    return left < right;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> x(n), y(n);
    map<int, vector<pair<int, char>>> ma;
    rep(i,n) {
        cin >> x[i] >> y[i];
    }
    string s; cin >> s;
    rep(i,n) {
        ma[y[i]].push_back({x[i], s[i]});
    }
    for(auto const& [key, val] : ma) {
        if(hasCollitionHappen(val)) {
            puts("Yes");
            return 0;
        };
    }
    puts("No");

    return 0;
}