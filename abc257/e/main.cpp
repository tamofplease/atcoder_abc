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
    int n;
    cin >> n;
    vector<int> c(9);
    int mi = n + 1;
    int miIndex = -1;
    rep(i, 9) {
        cin >> c[i];
        if (c[i] <= mi) {
            miIndex = i + 1;
            mi = c[i];
        }
    }
    string s = "";

    while (n - mi >= 0) {
        n -= mi;
        s.push_back(miIndex + '0');
    }
    int m = s.length();
    rep(i, m) {
        for (int j = 8; j >= 0; j--) {
            if (s[i] <= (j + 1) + '0' && n >= (c[j] - mi)) {
                n -= c[j] - mi;
                s[i] = (j + 1) + '0';
                continue;
            }
        }
    }
    cout << s << endl;
    return 0;
}
