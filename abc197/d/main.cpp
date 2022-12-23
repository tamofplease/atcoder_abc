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

using C = complex<double>;

C inC() {
    double x, y;
    cin >> x >> y;
    return C(x, y);
}

int main() {
    int n;
    cin >> n;
    C s = inC(), g = inC();
    C o = (s + g) / 2.0;
    double PI = acos(-1);
    double rad = PI * 2 / (double)n;
    C r(cos(rad), sin(rad));
    C ans = o + (s - o) * r;
    printf("%.11f %.11f\n", ans.real(), ans.imag());
}
