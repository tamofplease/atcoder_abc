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
    string a, b, c;
    cin >> a >> b >> c;
    set<char> se;
    for (char cc : a) se.insert(cc);
    for (char cc : b) se.insert(cc);
    for (char cc : c) se.insert(cc);
    if (se.size() > 10) {
        puts("UNSOLVABLE");
        return 0;
    }
    vector<char> v;
    for (char cc : se) v.push_back(cc);
    while (v.size() < 10) v.push_back('.');
    sort(ALL(v));
    do {
        unordered_map<char, int> ma;
        for (int i = 0; i < 10; i++) {
            if (v[i] == '.') continue;
            ma[v[i]] = i;
        }
        if (ma[a[0]] == 0 || ma[b[0]] == 0 || ma[c[0]] == 0) continue;
        ll a_i = 0, b_i = 0, c_i = 0;
        for (char aa : a) a_i = a_i * 10 + ma[aa];
        for (char aa : b) b_i = b_i * 10 + ma[aa];
        for (char aa : c) c_i = c_i * 10 + ma[aa];
        if (a_i + b_i == c_i) {
            cout << a_i << endl << b_i << endl << c_i << endl;
            return 0;
        }
    } while (next_permutation(ALL(v)));
    puts("UNSOLVABLE");
    return 0;
}
