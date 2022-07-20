// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define Rep(i, n) for (int i = 1 ; i <= n ; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    vector<int> v(n);
    for (auto& ref : v) {
        cin >> ref;
        dq.push_back(ref);
    }
    int ans = 0;
    auto trying = [&](deque<int> d, int a, int b, int c) -> int {
        priority_queue<int, vector<int>, greater<int>> pq;
        int tmp = 0;
        rep(i, a) {
            if (d.empty()) {
                break;
            }
            tmp += d.front();
            pq.push(d.front());
            d.pop_front();
        }
        rep(i, b) {
            if (d.empty()) {
                break;
            }
            tmp += d.back();
            pq.push(d.back());
            d.pop_back();
        }
        rep(i, c) {
            if (pq.empty()) {
                break;
            }
            tmp -= pq.top();
            pq.pop();
        }
        return tmp;
    };
    vector<vector<int>> data;
    auto bld = [&](auto f, vector<int> cur, int remain) {
        if (cur.size() == 3) {
            data.push_back(cur);
            return;
        }
        rep(i, remain + 1) {
            cur.push_back(i);
            f(f, cur, remain - i);
            cur.pop_back();
        }
    };
    bld(bld, {}, k);
    for (vector<int> dt : data) {
        deque<int> d = dq;
        ans = max(ans, trying(d, dt[0], dt[1], dt[2]));
    }

    cout << ans << endl;

    return 0;
}
