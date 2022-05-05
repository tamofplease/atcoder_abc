#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;


struct query {
    int a, b, c, d;
    query(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {};
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m, q; cin >> n >> m >> q;
    vector<query> queries;
    rep(i,q) {
        int a,b,c,d; cin >> a  >> b >> c >> d;
        a--; b--;
        queries.push_back(query(a,b,c,d));
    }
    int ans = 0;
    vector<int> cur;
    auto recursion = [&](auto f, int num, int tail) -> void {
        if(num == n) {
            int score = 0;
            for(query q: queries) {
                if(cur[q.b]-cur[q.a] == q.c) score += q.d;
            }
            ans = max(ans, score);
            return;
        }
        for(int i=tail;i<=m;i++) {
            cur.push_back(i);
            f(f, num+1, i);
            cur.pop_back();
        }
        return;
    };
    recursion(recursion, 0, 1);
    cout << ans << endl;

    return 0;
}
