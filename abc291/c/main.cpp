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
    string s;
    cin >> s;
    set<pair<int, int>> been;
    map<char, pair<int, int>> d = {{'R', {1, 0}}, {'L', {-1, 0}}, {'U', {0, 1}}, {'D', {0, -1}}};
    pair<int, int> prev = {0, 0};
    been.insert(prev);
    for (char c : s) {
        prev = {prev.first + d[c].first, prev.second + d[c].second};
        if (been.count(prev)) {
            puts("Yes");
            return 0;
        }
        been.insert(prev);
    }
    puts("No");

    return 0;
}
