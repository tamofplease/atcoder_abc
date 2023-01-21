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
    set<string> cur;
    map<string, string> to, origin;
    rep(i, n) {
        string s, t;
        cin >> s >> t;
        cur.insert(s);
        to[s] = t;
        origin[t] = s;
    }
    queue<string> q;
    for (const string p : cur) {
        string nxt = to[p];
        if (cur.count(nxt)) continue;
        q.push(p);
    }

    while (!q.empty()) {
        string base = q.front();
        q.pop();
        string nxt = to[base];
        to.erase(base);

        cur.erase(base);
        cur.insert(nxt);

        if (origin.count(base)) {
            string prev = origin[base];
            origin.erase(base);
            q.push(prev);
        }
    }
    if (to.size() == 0)
        puts("Yes");
    else
        puts("No");

    return 0;
}