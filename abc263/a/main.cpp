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
    map<int, int> ma;
    rep(i, 5) {
        int a;
        cin >> a;
        ma[a]++;
    }
    bool three = false;
    bool two = false;
    for (auto it : ma) {
        if (it.second == 2) two = true;
        if (it.second == 3) three = true;
    }
    if (three && two) {
        puts("Yes");
    } else {
        puts("No");
    }

    return 0;
}
