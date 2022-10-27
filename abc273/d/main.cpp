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
    int h, w, row, col;
    cin >> h >> w >> row >> col;
    int n;
    cin >> n;
    map<int, set<int>> rows, cols;
    rep(i, n) {
        int r, c;
        cin >> r >> c;
        rows[r].insert(c);
        cols[c].insert(r);
    }
    unordered_map<char, int> direction = {{'L', 0}, {'R', 2}, {'U', 1}, {'D', 3}};
    int q;
    cin >> q;
    rep(i, q) {
        char d;
        int l;
        cin >> d >> l;
        int move = direction[d];
        int type = (move & 1) ? row : col;
        set<int>& tgt = ((move & 1) ? cols[col] : rows[row]);
        auto it = tgt.upper_bound(type);
        int nxt = type + ((move & 2) ? 1 : -1) * l;
        if (move & 2) {
            chmin(nxt, ((it == tgt.end()) ? ((move & 1) ? h : w) : *it - 1));
        } else {
            chmax(nxt, ((it == tgt.begin()) ? 1 : *(--it) + 1));
        }
        ((move & 1) ? row : col) = nxt;
        cout << row << " " << col << endl;
    }

    return 0;
}
