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
    unordered_set<string> se;
    string start = "atcoder";

    queue<pair<int, string>> q;
    q.push({0, start});
    while (q.size()) {
        auto t = q.front();
        string cur = t.second;
        if (cur == s) {
            cout << t.first << endl;
            return 0;
        }
        q.pop();
        rep(i, 7) {
            swap(cur[i], cur[i + 1]);
            if (se.find(cur) == se.end()) {
                se.insert(cur);
                q.push({t.first + 1, cur});
            }
            swap(cur[i], cur[i + 1]);
        }
    }
    return 0;
}