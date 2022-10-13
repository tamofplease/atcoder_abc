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

int send(int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    cin >> a;
    return a;
}

int main() {
    int n;
    cin >> n;
    int left = 1, right = n + 1;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        int res = send(left, mid - 1, 1, n);
        if (res == mid - left)
            left = mid;
        else
            right = mid;
    }
    int bottom = 1, top = n + 1;
    while (top - bottom > 1) {
        int mid = (top + bottom) / 2;
        int res = send(1, n, bottom, mid - 1);
        if (res == mid - bottom)
            bottom = mid;
        else
            top = mid;
    }
    cout << "! " << left << " " << bottom << endl;
    return 0;
}
