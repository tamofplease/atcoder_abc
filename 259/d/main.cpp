// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

struct Circle {
    ll x, y, r;
    Circle(int x, int y, int r) : x(x), y(y), r(r) {}
};

ll getDistance(pair<int, int> a, pair<int, int> b) {
    ll c = abs(a.first - b.first);
    ll d = abs(a.second - b.second);
    return c * c + d * d;
}

bool isConnected(Circle a, Circle b) {
    ll d = getDistance({a.x, a.y}, {b.x, b.y});
    bool cond1 = d <= (a.r + b.r) * (a.r + b.r);
    bool cond2 = d >= (a.r - b.r) * (a.r - b.r);
    return cond1 && cond2;
}

int main() {
    int n;
    cin >> n;
    pair<int, int> s, g;
    cin >> s.first >> s.second >> g.first >> g.second;

    vector<Circle> circles;
    vector<int> starts;
    vector<int> goals;
    vector<vector<int>> to(n);
    rep(i, n) {
        ll x, y, r;
        cin >> x >> y >> r;
        if (getDistance({x, y}, s) == r * r) {
            starts.push_back(i);
        }
        if (getDistance({x, y}, g) == r * r) {
            goals.push_back(i);
        }
        circles.emplace_back(x, y, r);
    }
    rep(i, n) rep(j, i) {
        if (isConnected(circles[i], circles[j])) {
            to[i].push_back(j);
            to[j].push_back(i);
        }
    }

    // for (int g : goals) {
    //     cout << g << " ";
    // }
    // cout << endl;
    // for (int s : starts) {
    //     cout << s << " ";
    // }
    // cout << endl;

    // for (vector<int> t : to) {
    //     rep(i, t.size()) { cout << t[i] << " "; }
    //     cout << endl;
    // }

    map<pair<int, int>, bool> memo;
    queue<int> q;
    vector<int> been(n, false);
    for (int st : starts) {
        q.push(st);
        been[st] = true;
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt : to[cur]) {
            if (!been[nxt]) {
                been[nxt] = true;
                q.push(nxt);
            }
        }
    }

    for (int goal : goals) {
        if (been[goal]) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
