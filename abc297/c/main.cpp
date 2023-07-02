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
    int h, w;
    cin >> h >> w;
    vector<string> s;
    rep(i, h) {
        string ss;
        cin >> ss;
        rep(j, w - 1) {
            if (ss[j] == 'T' && ss[j + 1] == 'T') {
                ss[j] = 'P';
                ss[j + 1] = 'C';
            }
        }
        s.push_back(ss);
    }

    rep(i, h) { cout << s[i] << endl; }
    return 0;
}
