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
    int second = n / 16, first = n % 16;
    if (second >= 10) {
        cout << char(second - 55);
    } else {
        cout << second;
    }
    if (first > 9) {
        cout << char(first + 55);
    } else {
        cout << first;
    }
    cout << endl;
    return 0;
}
