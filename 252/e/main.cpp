// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

struct Edge {
    int to;
    int cost;
    explicit Edge(int to, int cost) : to(to), cost(cost) {}
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> to;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        to[a].push_back(Edge(b, c));
        to[b].push_back(Edge(a, c));
    }
    
    return 0;
}
