// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> ans;

    vector<int> ball(n + 1, 0);
    for (int i = n; i >= 1; i--) {
        int cnt = 0;
        int j = i * 2;
        while (j <= n) {
            cnt += ball[j];
            j += i;
        }
        ball[i] = a[i - 1] != (cnt % 2);
        if (ball[i] > 0) {
            ans.push_back(i);
        }
    }
    sort(ALL(ans));
    cout << ans.size() << endl;
    for (int aa : ans) {
        cout << aa << endl;
    }

    return 0;
}
