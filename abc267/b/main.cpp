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
    string s;
    cin >> s;
    int n = s.length();
    if (s[0] == '1') {
        puts("No");
        return 0;
    }
    set<int> se;
    vector<int> v = {3, 2, 4, 1, 3, 5, 0, 2, 4, 6};
    rep(i, n) if (s[i] - '0') se.insert(v[i]);
    for (int left : se)
        for (int right : se) {
            if (left >= right) continue;
            for (int mid = left + 1; mid < right; mid++) {
                if (se.find(mid) == se.end()) {
                    puts("Yes");
                    return 0;
                }
            }
        }
    puts("No");

    return 0;
}
