// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    int ma = max(a, max(b,c));
    int mi = min(a, min(b, c));
    if (sum - ma - mi == b) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}
