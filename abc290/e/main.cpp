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
    map<int, int> ma;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        ma[a[i]]++;
    }
    ll ans = 0;
    ll m = n;
    ll front = 0, back = n - 1;
    while (front < back) {
        // front_part
        n--;
        ma[a[front]]--;
        ans += (front + 1) * (n - ma[a[front]]);
        front++;
        if (front >= back) break;
        // back_part
        n--;
        ma[a[back]]--;
        ans += (m - back) * (n - ma[a[back]]);
        back--;
    }
    cout << ans << endl;
    return 0;
}
