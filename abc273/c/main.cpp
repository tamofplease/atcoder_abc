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
    vector<int> a(n);
    unordered_map<int, int> ma;
    for (int& ref : a) cin >> ref;
    sort(a.begin(), a.end());
    int prev = -1;
    for (const int aa : a) {
        if (prev != aa) {
            prev = aa;
            ma[prev] = ma.size() + 1;
        }
    }
    vector<int> ans(n, 0);
    for (const int aa : a) ans[ma.size() - ma[aa]]++;

    for (const int i : ans) cout << i << endl;
    return 0;
}
