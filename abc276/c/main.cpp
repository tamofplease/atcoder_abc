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
    vector<int> p(n);
    for (int& ref : p) cin >> ref;
    bool come = false;
    do {
        if (come) {
            for (const int pp : p) cout << pp << " ";
            break;
        }
        come = true;
    } while (prev_permutation(p.begin(), p.end()));
    cout << endl;
    return 0;
}
