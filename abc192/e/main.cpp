// Copyright 2022 tamofplease. All rights reserved.

#include <bits/stdc++.h>
#include <atcoder/all>

#define rep(i, n) for (int i = 0; i < n ; i++)
#define Rep(i, n) for (int i = 1; i <= n ; i++)

#define ll int64_t
struct data {
    int to;
    int time;
    int leave;
    data(int to, ll time, ll leave) : to(to), time(time), leave(leave) {}
};

template<typename T> using min_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;


int main() {
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    x--;
    y--;
    std::vector<std::vector<data>> edge(n);
    rep(i, m) {
        int a, b;
        ll t, k;
        std::cin >> a >> b >> t >> k;
        a--;
        b--;
        edge[a].push_back(data(b, t, k));
        edge[b].push_back(data(a, t, k));
    }
    std::vector<ll> visited(n, INT64_MAX);
    std::vector<bool> hasCome(n, false);
    min_priority_queue<std::pair<ll, int>> q;
    q.push({0, x});
    while (!q.empty()) {
        std::pair<ll, int> cur = q.top();
        q.pop();
        if (cur.second == y) {
            std::cout << visited[y] << std::endl;
            return 0;
        }
        if (hasCome[cur.second]) continue;
        hasCome[cur.second] = true;
        for (data d : edge[cur.second]) {
            ll tmp = (cur.first + d.leave - 1) / d.leave * d.leave + d.time;
            if (visited[d.to] == -1 || visited[d.to] > tmp) {
                visited[d.to] = tmp;
                q.push({tmp, d.to});
            }
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}
