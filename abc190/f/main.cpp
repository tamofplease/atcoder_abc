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

struct BIT {
   private:
    vector<int> bit;
    int n;

   public:
    BIT(int size) {
        n = size;
        bit.resize(n + 1);
    }

    void add(int a, int w) {
        for (int x = a; x <= n; x += x & -x) bit[x] += w;
    }
    int sum(int a) {
        int ret = 0;
        for (int x = a; x > 0; x -= x & -x) ret += bit[x];
        return ret;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ref : a) {
        cin >> ref, ref++;
    }
    ll ans = 0;
    BIT b(n);
    for (int i = 0; i < n; i++) {
        ans += i - b.sum(a[i]);
        b.add(a[i], 1);
    }
    cout << ans << endl;
    for (int i = 0; i < n - 1; i++) {
        ans += (n - a[i]) - (a[i] - 1);
        cout << ans << endl;
    }
    return 0;
}
