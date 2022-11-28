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
    int n;
    cin >> n;
    if (n == 1) {
        printf("%.12f\n", 1.0);
        return 0;
    }
    if (n == 2) {
        printf("%.11f\n", 2.0);
        return 0;
    }
    double base = 0;
    Rep(i, n - 1) { base += (double)n / i; }
    printf("%.11f\n", base);
    return 0;
}
