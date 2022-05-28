// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k);
    int ma = -1;
    for(auto& ref : a) {
        cin >> ref;
    }
    for (int aa : a) {
        ma = max(aa, ma);
    }
    bool flag = true;

    for (auto& ref : b) {
        cin >> ref;
    }
    for (int bb : b) {
        if (a[bb-1] == ma) {
            puts("Yes");
            return 0;
        }
    }

    puts("No");

    return 0;
}
