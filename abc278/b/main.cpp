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

bool isValid(int h, int m) { return 0 <= h && h < 24 && 0 <= m && m < 60; }
pair<int, int> nxt(int h, int m) {
    if (m != 59) return {h, m + 1};
    if (h != 23) return {h + 1, 0};
    return {0, 0};
}
bool isMissing(int h, int m) {
    string h_s = to_string(h), m_s = to_string(m);
    if (h < 10) h_s = "0" + h_s;
    if (m < 10) m_s = "0" + m_s;
    swap(h_s[1], m_s[0]);
    return isValid(stoi(h_s), stoi(m_s));
}
int main() {
    int h, m;
    cin >> h >> m;

    while (!isMissing(h, m)) {
        pair<int, int> nt = nxt(h, m);
        h = nt.first, m = nt.second;
    }
    cout << h << " " << m << endl;

    return 0;
}
