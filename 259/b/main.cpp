// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    int a, b, d;
    cin >> a >> b >> d;
    double si = sin(d * M_PI / 180);
    double co = cos(d * M_PI / 180);
    printf("%.9f %.9f\n", co * a - si * b, si * a + co * b);

    return 0;
}
