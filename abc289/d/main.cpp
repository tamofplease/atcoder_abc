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

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (auto& ref : a) cin >> ref;
    vector<bool> reach(200000 + 1, false), fin(200000 + 1, false);
    cin >> m;
    rep(i, m) {
        int b;
        cin >> b;
        fin[b] = true;
    }
    int x;
    cin >> x;
    reach[0] = true;
    for (int i = 0; i < x; i++) {
        if (reach[i] && !fin[i]) {
            for (int j = 0; j < n; j++) reach[i + a[j]] = true;
        }
    }
    if (reach[x])
        puts("Yes");
    else
        puts("No");

    return 0;
}
