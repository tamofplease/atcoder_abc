// "Copyright 2022 tam"
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

struct Cake {
    ll x, y, z;
    Cake(ll x, ll y, ll z) : x(x), y(y), z(z){};
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Cake> cakes;
    rep(i, n) {
        ll x, y, z;
        cin >> x >> y >> z;
        cakes.emplace_back(x, y, z);
    }

    // see from 1 to i's cake, select m cakes then sum of x,y,z;
    vector<vector<Cake>> dp(n + 1, vector<Cake>(m + 1, Cake(0, 0, 0)));

    for (int i = 1; i <= n; i++) {
        const Cake& tgt = cakes[i - 1];
        for (int j = 1; j <= m; j++) {
            if () dp[i][j] = dp[i - 1][j - 1];
        }
    }

    return 0;
}
